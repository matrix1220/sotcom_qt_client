import QtQuick 2.5
import QtQuick.Window 2.2

CWindow {
    title: "Error"
    visible: true

//    Image {
//        width: 50
//        fillMode: Image.PreserveAspectFit
//        source: "error.png"
//        anchors.right: message.left
//        anchors.verticalCenter: message.verticalCenter
//    }

    Text {
        id: message
        anchors.centerIn: parent
        text: app.err_str
    }

}
