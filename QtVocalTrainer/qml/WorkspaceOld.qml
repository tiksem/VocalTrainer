import QtQuick 2.0
import "js/canvasutils.js" as CanvasUtils
import "js/mathutils.js" as MathUtils

Rectangle {
    id: root
    property var piano
    property var verticalScroll
    property var horizontalScroll

    property var pitchInputReader
    property var tempo
    property var player

    readonly property string gridColor: "#338B89B6"
    readonly property string accentGridColor: "#808B89B6"
    readonly property string graphColor: "#FF5E85"

    property var zoom: zoom

    onZoomChanged: {
//        zoom.zoomChanged.connect(grid.requestPaint)
    }

    onVerticalScrollChanged: {
//        verticalScroll.positionChanged.connect(grid.requestPaint)
//        horizontalScroll.positionChanged.connect(grid.requestPaint)
    }

    function getVerticalOffset() {
        return height - verticalScroll.position * height
    }

    function getHorizontalOffset() {
        return width * horizontalScroll.position / horizontalScroll.pageSize
    }

    Canvas {
        id: grid
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: parent.height
        renderStrategy: Canvas.Threaded
        renderTarget: Canvas.FramebufferObject

        property real frameTime: 0

        property real horizontalOffset

        Timer {
            interval: 1
            running: player.isPlaying
            repeat: true

            onTriggered: {
                grid.horizontalOffset = grid.width * (cpp.now() - player.playStartedTime) / player.duration / horizontalScroll.pageSize
                console.log("grid.horizontalOffset = " + grid.horizontalOffset)
            }
        }

        onPaint: {
            var now = cpp.now()
            if (frameTime) {
                var fps = 1.0 / (now - frameTime)
                //console.log("fps = " + fps)
            }
            frameTime = now

            var ctx = getContext("2d")
            ctx.fillStyle = "white"
            ctx.fillRect(0, 0, width, height)

            var verticalOffset = getVerticalOffset()

            zoom.iterateIntervals(root, {
                beatsIterator: function(x, isBeat) {
                    // draw beats and tacts
                    ctx.beginPath();
                    ctx.moveTo(x, 0);
                    ctx.lineTo(x, height);
                    ctx.strokeStyle = isBeat ? gridColor : accentGridColor
                    ctx.stroke();
                },
                verticalIterator: function(y, isOctaveBegin) {
                    // draw pitch horizontal lines
                    ctx.beginPath();
                    ctx.moveTo(0, y);
                    ctx.lineTo(width, y);
                    ctx.strokeStyle = isOctaveBegin ? accentGridColor : gridColor;
                    ctx.stroke();
                },
                verticalOffset: verticalOffset,
                horizontalOffset: horizontalOffset
            });
        }
    }

    Canvas {
        id: pitches
        renderStrategy: Canvas.Cooperative
        renderTarget: Canvas.FramebufferObject
        height: parent.height
        width: parent.width

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

//            var duration = player.duration
//            var begin = duration * horizontalScroll.position
//            var end = begin + duration * horizontalScroll.pageSize
        }
    }

    Canvas {
        id: pitchGraph
        renderStrategy: Canvas.Cooperative
        renderTarget: Canvas.FramebufferObject
        height: parent.height
        width: zoom.getIntervalWidth() * 4;

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            var pitchesCount = pitchInputReader.pitchesCount
            if (pitchesCount <= 0) {
                return
            }

            // drawing area - 4 beats
            var duration = 60.0 / tempo.tempo * 4

            var pitchIndex = pitchesCount - 1
            while (pitchIndex >= 0 && !pitchInputReader.pitchAt(pitchIndex).isValid) {
                pitchIndex--;
            }

            var points = []
            var now = cpp.now()
            while(pitchIndex >= 0) {
                var pitch = pitchInputReader.pitchAt(pitchIndex)
                var x = (pitch.time - now + duration) / duration * width
                var perfectFrequencyIndex = pitch.perfectFrequencyIndex
                if (perfectFrequencyIndex >= 0) {
                    var distanceFromFirstPitch = perfectFrequencyIndex - piano.firstPitch.perfectFrequencyIndex
                    var y = height - (distanceFromFirstPitch + pitch.distanceFromLowerBound / 2.0) * zoom.getIntervalHeight()
                    points.push(Qt.point(x, y))
                } else {
                    points.push(undefined)
                }

                if (x <= 0) {
                    break
                }

                pitchIndex--
            }

            CanvasUtils.drawPitchGraph(ctx, points, graphColor)
        }
    }

    Timer {
        interval: 1000 / 60.0 //60 fps
        repeat: true
        running: true

        onTriggered: {
            pitchGraph.requestPaint()
            grid.requestPaint()
        }
    }
}