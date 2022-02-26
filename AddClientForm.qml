import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

CWindow {
    title: "Add Client"
    visible: true
    width: 300
    height: 300

    Column {

        TextEdit {
            id: firstname
            text: "firstname"
        }

        Button {
            text: "add"
            onClicked: app.newClient(firstname.text)
        }
    }


}
