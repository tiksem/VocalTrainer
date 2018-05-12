import QtQuick 2.0

Rectangle {
    property var zoom

    readonly property real dotRadius: 1.5
    readonly property string dotColor: "#24232D"

    height: 13.5

    Canvas {
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            var dotY = height / 2

            var tact = 1;
            zoom.iterateIntervals(this, {
                beatsIterator: function(x, isBeat) {
                    if (isBeat) {
                        ctx.fillStyle = dotColor;
                        ctx.beginPath();
                        ctx.arc(x, dotY, dotRadius, 0, 2 * Math.PI);
                        ctx.fill();
                    } else {
                        ctx.font = "12px Arial"
                        ctx.fillStyle = dotColor
                        ctx.textAlign = "center"
                        ctx.textBaseline="middle"
                        ctx.fillText(tact.toString(), x, dotY);
                        tact++;
                    }
                }
            })
        }
    }
}
