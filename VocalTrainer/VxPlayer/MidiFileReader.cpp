//
// Created by Ivan Kuskov on 3/28/18.
// Copyright (c) 2018 Mac. All rights reserved.
//

#include "MidiFileReader.h"
#include "MidiFile.h"

#include <iostream>
#include <algorithm>

static constexpr int    MAX_MIDI_CHANNELS = 15;

static constexpr int    NO_CHANNEL_PREFIX = -1;

// MIDI Message = array[status_midi_message_byte, midi_message_byte_1, midi_message_byte_2, midi_message_byte_3, ...]
static constexpr int    STATUS_MIDI_MESSAGE_BYTE_INDEX = 0;
static constexpr int    MIDI_MESSAGE_BYTE_INDEX_1 = 1;
static constexpr int    MIDI_MESSAGE_BYTE_INDEX_2 = 2;
static constexpr int    MIDI_MESSAGE_BYTE_INDEX_3 = 3;

static constexpr int    MIN_NOTE_COUNT = 40;
static constexpr int    MAX_NOTE_COUNT = 1000;
static constexpr double MAX_TRACK_DURATION = 3600;
static constexpr int    DRUMS_CHANNEL_ID = 9;

static constexpr double NAME_WEIGHT = 3.0;
static constexpr double NOTE_COUNT_WEIGHT = 2.0;

static constexpr double LOWEST_NOTE_WEIGHT = 1.0;
static constexpr double LOWEST_NOTE_MX = 58.5;
static constexpr double LOWEST_NOTE_SIGMA = 9.25;

static constexpr double HEIGHEST_NOTE_WEIGHT = 1.0;
static constexpr double HEIGHEST_NOTE_MX = 74.91;
static constexpr double HEIGHEST_NOTE_SIGMA = 8.84;

static constexpr double RANGE_OF_NOTES_WEIGHT = 1.0;
static constexpr double RANGE_OF_NOTES_MX = 16.0;
static constexpr double RANGE_OF_NOTES_SIGMA = 7.0;

static constexpr double MAX_NOTE_VALUE_WEIGHT = 1.0;
static constexpr double MAX_NOTE_VALUE_MX = 63.0;
static constexpr double MAX_NOTE_VALUE_SIGMA = 21.0;

static constexpr double NOTES_PER_SECOND_WEIGHT = 1.0;
static constexpr double NOTES_PER_SECOND_MX = 2.43;
static constexpr double NOTES_PER_SECOND_SIGMA = 1.95;

static constexpr char   SUBSTRING_VOCAL[]  = "vocal";
static constexpr char   SUBSTRING_LEAD[]   = "lead";
static constexpr char   SUBSTRING_SONG[]   = "song";
static constexpr char   SUBSTRING_MELODY[] = "melod";

MidiFileReader::MidiFileReader()
{

}

MidiFileReader::~MidiFileReader()
{

}

std::vector<VxFile> MidiFileReader::read(const string &filename)
{
    MidiFile f;
    if (f.read(filename) != 0) {
        return processMidiFile(f);
    } else {
        return std::vector<VxFile>();
    }
}

std::vector<VxFile> MidiFileReader::read(istream &is)
{
    MidiFile f;
    if (f.read(is) != 0) {
        return processMidiFile(f);
    } else {
        return std::vector<VxFile>();
    }
}

/*!
 * \brief MidiFileReader::processMidiFile
 *
 * Processes MidiFile object
 * \param midi
 * \return
 */
std::vector<VxFile> MidiFileReader::processMidiFile(MidiFile &midi)
{
    currentChannelPrefix = NO_CHANNEL_PREFIX;
    durationInSeconds = midi.getTotalTimeInSeconds();
    durationInTicks = midi.getTotalTimeInTicks();
    tpq = midi.getTPQ();
    tps = durationInTicks / durationInSeconds;

    int trackCount = midi.getTrackCount();
    for (int track = 0; track < trackCount; ++ track) {
        for (size_t event = 0; event < midi[track].size(); ++ event) {
            processEvent(midi[track][event]);
        }
    }
    postProcess();
    auto trackList = getAvailableTracks();
    std::vector<VxFile> result;
    for (auto track : trackList) {
        std::vector<VxPitch> pitches;
        for (auto note : track->getNotes()) {
            VxPitch pitch;
            pitch.pitch = Pitch::fromMidiIndex(note->keyNumber);
            pitch.startBitNumber = note->startTick;
            pitch.bitsCount = note->durationInTicks();
            pitches.emplace_back(std::move(pitch));
        }
        result.emplace_back(pitches, durationInTicks - track->finalTick, tps * 60.0);
    }
    return result;
}

/*!
 * \brief MidiFileReader::processEvent
 *
 * Processes single MIDI or META event
 * \param event
 */
void MidiFileReader::processEvent(const MidiEvent &event)
{
    int eventChannelID = event.getChannel();
    int eventTrackID = event.track;
    int eventTick = event.tick;

    //! ***********************************************
    //! All the data below was got from tutorial      *
    //! http://www.somascape.org/midi/tech/mfile.html *
    //! ***********************************************

    // META events
    if (event.isMeta()) {
        switch (event.getP1()) {
        // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // FF 03 length text.
        // This event is optional. It's interpretation depends on its context. If it occurs in the first track of a format 0 or 1 MIDI file, then it gives the Sequence Name. Otherwise it gives the Track Name
        case 0x03: {
            std::string trackName = eventText(event, MIDI_MESSAGE_BYTE_INDEX_3, event[MIDI_MESSAGE_BYTE_INDEX_2]);
            trackNamesMap[eventTrackID] = trackName;
            break;
        }
            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // FF 04 length text
            // Instrument name of length. This optional event is used to provide a textual clue regarding the intended instrumentation for a track (e.g. 'Piano' or 'Flute', etc). If used, it is reccommended to place this event near the start of a track)
        case 0x04: {
            std::string instrumentName = eventText(event, MIDI_MESSAGE_BYTE_INDEX_3, event[MIDI_MESSAGE_BYTE_INDEX_2]);
            // If prefix is set, appending name to track
            if (currentChannelPrefix != NO_CHANNEL_PREFIX) {
                auto track = getTrack(eventTrackID, currentChannelPrefix);
                track->instrumentName = instrumentName;
            }
            break;
        }
            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // FF 20 01 сс
            // Midi channel prefix (cc is a byte specifying the MIDI channel (0-15). This optional event is used to associate any subsequent SysEx and Meta events with a particular MIDI channel, and will remain in effect until the next MIDI Channel Prefix Meta event or the next MIDI event)
        case 0x20: {
            currentChannelPrefix = event[MIDI_MESSAGE_BYTE_INDEX_3];
            break;
        }
            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // FF 2F 00
            // End of track
        case 0x2F: {
            for (auto track: tracksMap) {
                if(track.second->trackId == eventTrackID) {
                    track.second->closeAllNotes(eventTick);
                    track.second->finalTick = eventTick;
                }
            }
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // FF 51 03 tt tt tt
            // Tempo (tt tt tt is a 24-bit value specifying the tempo as the number of microseconds per quarter note)
        case 0x51: {
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // FF 20 01 сс
            // Key signature (sf is a byte specifying the number of flats (-ve) or sharps (+ve) that identifies the key signature (-7 = 7 flats, -1 = 1 flat, 0 = key of C, 1 = 1 sharp, etc). mi is a byte specifying a major (0) or minor (1) key)
        case 0x59: {
            break;
        }

        default: {
            break;
        }
        }
    } else {
        currentChannelPrefix = NO_CHANNEL_PREFIX; // If event is midi-event, channel prefix removes
        int command = event.getCommandNibble(); // P0 & 0x11110000
        auto currentTrack = getTrack(eventTrackID, eventChannelID);

        switch (command) {

        // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // 8n note velocity
        // Note OFF (Stop sounding the specified note, on MIDI channel n)
        case 0x80: {
            currentTrack->closeNote(event.getKeyNumber(), eventTick);
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // 9n note velocity
            // Note ON (Start sounding the specified note, on MIDI channel n)
        case 0x90: {
            //            debugEvent(event);
            int keyNumber = event.getKeyNumber();
            int velocity = event.getVelocity();
            if (velocity == 0) { // same as Note OFF
                currentTrack->closeNote(keyNumber, eventTick);
            } else {
                currentTrack->openNote(keyNumber, eventTick, velocity);
            }
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // An note pressure
            // Polyphonic Pressure (Apply aftertouch pressure to the specified note, on MIDI channel n)
        case 0xA0: {
            currentTrack->isPolyphonical = true;
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // Bn controller value
            // Controller (Set the specified controller, on MIDI channel n, to value)
        case 0xB0: {
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // Cn program
            // Program Change (Select the specified program (i.e. voice, or instrument), on MIDI channel n)
        case 0xC0: {
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // Dn pressure
            // Channel Pressure (Apply aftertouch pressure to all notes currently sounding on MIDI channel n)
        case 0xD0: {
            break;
        }

            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // En lsb msb
            // Pitch Bend (Apply pitch bend to all notes currently sounding on MIDI channel n)
        case 0xE0: {
            break;
        }
        default: {
            break;
        }
        }
    }
}

/*!
 * \brief MidiFileReader::getTrack
 *
 * Returns track with trackID and channelID, and if this track not exists, creates it
 * \param trackID
 * \param channelID
 * \return
 */
std::shared_ptr<MidiTrack> MidiFileReader::getTrack(const int trackID, const int channelID)
{
    int id = trackID * MAX_MIDI_CHANNELS + channelID;
    TrackMap::iterator it = tracksMap.find(id);
    if (it == tracksMap.end()) {
        std::shared_ptr<MidiTrack> track = std::make_shared<MidiTrack>();
        tracksMap[id] = track;
        track->trackId = trackID;
        track->channelId = channelID;
        return track;
    } else {
        return it->second;
    }
}

/*!
 * \brief MidiFileReader::eventText
 * Transformates n bytes from start to ASCII-string
 *
 * \param event
 * \param start
 * \param n
 * \return
 */
string MidiFileReader::eventText(const MidiEvent &event, const int start, const int n)
{
    size_t fin = start + n;
    if (fin > event.size()) {
        fin = event.size();
    }
    std::string s;
    for (size_t i = start; i < fin; i++) {
        s += (char)event[i];
    }
    return s;
}

/*!
 * \brief MidiFileReader::postProcess
 *
 * Counts necessary values for all stored MIDI tracks
 */
void MidiFileReader::postProcess()
{
    for (auto trackMapItem : tracksMap) {
        std::shared_ptr<MidiTrack> track = trackMapItem.second;

        // Assigning track name
        TrackNamesMap::iterator it = trackNamesMap.find(track->trackId);
        if (it != trackNamesMap.end()) {
            track->trackName = it->second;
        }

        track->postProcess(tpq, durationInTicks);
        track->durationInTime = 1.0 * track->durationInTicks() / tps;
    }
}

/*!
 * \brief MidiFileReader::getTracks
 *
 * Gets track list that satisfies conditions
 * \return
 */
std::vector<std::shared_ptr<MidiTrack> > MidiFileReader::getAvailableTracks()
{
    std::vector<std::shared_ptr<MidiTrack> > tracks;

    // If duration is more than 1 hour, return nothing
    if (durationInSeconds > MAX_TRACK_DURATION)
        return tracks;
    for (auto trackMapItem : tracksMap) {
        // Throwing out drums, empty and polyphonical tracks;
        std::shared_ptr<MidiTrack> track = trackMapItem.second;
        if (track->noteCount > 0
                && (track->channelId != DRUMS_CHANNEL_ID)
                && (!track->isPolyphonical)
                ) {
            tracks.emplace_back(track);
        }
    }
    std::sort(tracks.begin(), tracks.end(), sortCompare);
    return tracks;
}

/*!
 * \brief MidiFileReader::sortAlghorythm
 *
 * Sort function to order tracks by the possibilities of being a vocal part
 * \param first
 * \param second
 * \return
 */
bool MidiFileReader::sortCompare(const std::shared_ptr<MidiTrack> &left, const std::shared_ptr<MidiTrack> &right)
{
    double lPoints = getSummaryWeight(left);
    double rPoints = getSummaryWeight(right);

    return lPoints > rPoints;
}

/*!
 * \brief MidiFileReader::getWeight
 *
 * Gets the weight of criteria value if it satisfies distribution with mean = mx and interval = sigma
 * \param value
 * \param baseWeight
 * \param mx
 * \param sigma
 * \return
 */
double MidiFileReader::getWeight(const double &value, const double &baseWeight, const double &mx, const double &sigma)
{
    bool isGood = satisfiesDistribution(value, mx, sigma);
    return isGood ? baseWeight : 0.0;
}

double MidiFileReader::getSummaryWeight(const std::shared_ptr<MidiTrack> &value) {
    double result = 0.0;

    if (containsTrackName(value->trackName + value->instrumentName)) {
        result += NAME_WEIGHT;
    }

    int noteCount = value->noteCount;
    if (noteCount >= MIN_NOTE_COUNT && noteCount <= MAX_NOTE_COUNT) {
        result += NOTE_COUNT_WEIGHT;
    }

    // Lowest note distribution
    result += getWeight(value->lowestNote,  LOWEST_NOTE_WEIGHT, LOWEST_NOTE_MX, LOWEST_NOTE_SIGMA);

    // Highest note distribution
    result += getWeight(value->highestNote,  HEIGHEST_NOTE_WEIGHT, HEIGHEST_NOTE_MX, HEIGHEST_NOTE_SIGMA);

    // Note range distribution
    result += getWeight(value->highestNote - value->lowestNote, RANGE_OF_NOTES_WEIGHT, RANGE_OF_NOTES_MX, RANGE_OF_NOTES_SIGMA);

    // Note values distribution
    result += getWeight(value->maxNoteValuePercent, MAX_NOTE_VALUE_WEIGHT, MAX_NOTE_VALUE_MX, MAX_NOTE_VALUE_SIGMA);

    // Notes per second distribution
    result += getWeight(noteCount / value->durationInTime, NOTES_PER_SECOND_WEIGHT, NOTES_PER_SECOND_MX, NOTES_PER_SECOND_SIGMA);

    return result;
}

/*!
 * \brief MidiFileReader::containsTrackName
 *
 * Returns if name contains some of widely-used vocal trackname substring
 * \param name
 * \return
 */
bool MidiFileReader::containsTrackName(const string &name)
{
    std::string s = name;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return     s.find(SUBSTRING_VOCAL)  != std::string::npos
            || s.find(SUBSTRING_LEAD)   != std::string::npos
            || s.find(SUBSTRING_SONG)   != std::string::npos
            || s.find(SUBSTRING_MELODY) != std::string::npos;
}

/*!
 * \brief MidiFileReader::satisfiesDistribution
 *
 * Returns true if value satisfies distribution with meaning value mx and sigma interval
 * \param value
 * \param mid
 * \param sko
 * \return
 */
bool MidiFileReader::satisfiesDistribution(const double &value, const double &mx, const double &sigma)
{
    return (value >= mx - sigma)
            && (value <= mx + sigma);
}