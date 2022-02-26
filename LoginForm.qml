import QtQuick 2.5
import QtQuick.Controls 2.5
import QtQuick.Window 2.2

CWindow {
    title: "Login"
    visible: true

    Column {
        spacing: 12
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter


        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Phone:"
        }
        Rectangle {
            anchors.horizontalCenter: parent.horizontalCenter
            //color: "#00000000"
            border.color: 'black'
            border.width: 1
            radius: 4
            width: input.width + 10
            height: input.height + 10



            TextInput {
                id: input
                font.pointSize: 14
                focus: true
                anchors.margins: 5

            }
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Ok"
            onClicked: app.check_login(input.text)
        }
    }

}
