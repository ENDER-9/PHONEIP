import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: originalWindow
    visible: true
    width: 1000
    height: 800
    title: qsTr("Spyculus | A Server - Client Phonebook")

    Rectangle {
        id: taskbarLeft
        color: "grey"
        width: 50
        height: originalWindow.height
        anchors.left: originalWindow.left
    }
}