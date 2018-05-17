import QtQuick 2.0

Item {
    id: scrollBar

    // position and pageSize are in the range 0.0 - 1.0.  They are relative to the
    property real position: 0
    property real positionIncrement: 0.01
    property real pageSize
    property real padding: 2.25
    property alias upScroller: upScroller
    property alias downScroller: downScroller

    width: 11.25

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#E8E7F0"
    }

    onPositionChanged: {
        stripe.y = position * mouseArea.drag.maximumY
    }

    Rectangle {
        id: stripe
        height: pageSize * parent.height
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: padding
        anchors.rightMargin: padding
        radius: width / 2

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            drag {
                target: parent
                minimumY: 0
                maximumY: scrollBar.height - parent.height
                axis: Drag.YAxis
            }
        }

        onYChanged: {
            scrollBar.position = y / mouseArea.drag.maximumY
        }

        color: "#615F97"
    }

    Timer {
        interval: 30
        id: upScroller
        triggeredOnStart: true
        repeat: true
        onTriggered: {
            if (position - positionIncrement >= 0) {
                position -= positionIncrement
            }
        }
    }

    Timer {
        interval: 30
        id: downScroller
        triggeredOnStart: true
        repeat: true
        onTriggered: {
            if (position + positionIncrement <= 1.0) {
                position += positionIncrement
            }
        }
    }
}
