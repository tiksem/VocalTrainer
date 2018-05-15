#ifndef QMLPITCH_H
#define QMLPITCH_H

#include <QObject>
#include "../PitchDetection/Pitch.h"

class QmlPitch : public Pitch
{
    Q_GADGET
    Q_PROPERTY(QString name READ getNameAsQString())
    Q_PROPERTY(int perfectFrequencyIndex READ getPerfectFrequencyIndex())
    Q_PROPERTY(int indexInOctave READ getPitchInOctaveIndex())
    Q_PROPERTY(int octave READ getOctave())
    Q_PROPERTY(float frequency READ getFrequency())
    Q_PROPERTY(bool isValid READ isValid())

    // Calculated using formula: n = log(fn / f0, a), where
    // A = 2**(1/24),
    // f0 - pitch lower bound frequency,
    // fn - pitch actual frequency
    // returns value (-1.0f, 1.0f). Where 0 - perfect frequency
    Q_PROPERTY(QString distanceToPerfectFrequency READ getDistanceToPerfectFrequency())
    // returns value (0.0f, 2.0f). Where 1.0 - perfect frequency
    Q_PROPERTY(QString distanceFromLowerBound READ getDistanceFromLowerBound())
public:
    QmlPitch(const Pitch& pitch);
    QmlPitch(const QmlPitch& pitch) = default;
    QmlPitch() = default;

    QString getNameAsQString() const;
};

#endif // QMLPITCH_H
