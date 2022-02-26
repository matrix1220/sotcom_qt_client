import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.5


CWindow {
    title: "sotuvchi"
    visible: true

//    ColumnLayout {
//        Layout.alignment: Qt.AlignTop
//        anchors.fill: parent

//        RowLayout {
//            Button {
//                text: "refresh"
//                onClicked: console.log(app.orders[0])
//            }
//        }

        ListView {
            anchors.fill: parent
//            Layout.fillHeight: true
//            Layout.fillWidth: true
            spacing: 1
            model: app.orders

            delegate: Rectangle {
                width: parent.width
                border.color: 'black'
                border.width: 1
                radius: 2
                anchors.margins: 5
                height: 32
                Text {
                    anchors.centerIn: parent
                    text: modelData[0]['name']
                }
            }
        }
    //}

}
