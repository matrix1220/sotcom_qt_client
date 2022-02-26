import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

CWindow {
    title: "sotuvchi"
    visible: true

    Text {
        text: app.courier.name
    }

    Button {
        anchors.centerIn: parent
        text: "Orders"
        onClicked: app.openOrders()
    }


}
