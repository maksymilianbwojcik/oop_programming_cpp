import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.6
import pl.gwizdz 1.0
import displacement 1.0
import speed 1.0
import acceleration 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Demo {
        id: demo1
        value: 10.2
        onTest: console.log("It works...")
    }

    Displacement {
        id: displacement
    }

    Speed {
        id: speed
    }

    Acceleration {
        id: acceleration
    }

    TextField {
        id: textField
        x: 43
        y: 76
        text: qsTr("")
    }

    Button {
        id: button
        x: 43
        y: 228
        text: qsTr("Button")
        onClicked: function() {
            displacement.value=textField.text;
            speed.value=displacement.value;
            textField1.text=speed.value
            acceleration.value=speed.value;
            textField2.text=acceleration.value;
        }
    }

    Label {
        id: label2
        x: 43
        y: 130
        text: qsTr("spd")
    }

    Label {
        id: label3
        x: 43
        y: 175
        text: qsTr("acc")
    }

    TextField {
        id: textField1
        x: 86
        y: 127
        text: qsTr("")
    }

    TextField {
        id: textField2
        x: 86
        y: 172
        text: qsTr("")
    }
}
