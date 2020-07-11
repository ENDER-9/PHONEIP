import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: originalWindow
    visible: true
    color: "#313536"
    width: 1316
    height: 900
    title: qsTr("A Server - Client Phonebook")

    SearchUserInterface { 
        id: searchUserInterface
        width: originalWindow.width - taskbarLeft.width
        height: originalWindow.height - taskbarTop.height
        anchors.left: taskbarLeft.right
        anchors.top: taskbarTop.bottom
        visible: false
    }


    Rectangle {
        id: taskbarTop
        color: "#535A5C"
        width: originalWindow.width
        height: 60
        anchors.top: originalWindow.top

    }

    Rectangle {
        id: taskbarLeft
        color: "#535A5C"
        width: 165
        height: originalWindow.height
        anchors.left: originalWindow.left

        //Taskbar Buttons
        Column {
            id: buttonMenu
            anchors.centerIn: taskbarLeft
            spacing: 2
            bottomPadding: 400

            RoundButton{
                id: searchPersonTaskbarButton
                width: taskbarLeft.width
                height: 50
                onClicked: {
                    searchPersonTaskbarButtonRectangle.border.color = "#F4F4F4"
                    addPersonTaskbarButtonRectangle.border.color = "#313536"
                    deletePersonTaskbarButtonRectangle.border.color = "#313536"
                    modifyPersonTaskbarButtonRectangle.border.color = "#313536"
                    searchUserInterface.visible = true}

                Rectangle {
                    id: searchPersonTaskbarButtonRectangle
                    anchors.fill: parent
                    color: "#535A5C"
                    border.width: 1
                    border.color: "#313536"
                    radius: 15

                    Text{
                        id: searchPersonTaskbarButtonText
                        text: "Search Person"
                        font.family: "Titillium Web"
                        font.pointSize: 13
                        anchors.centerIn: parent
                        color: "White"
                    }
                }



            }
            RoundButton{
                id: addPersonTaskbarButton
                width: taskbarLeft.width
                height: 50
                onClicked: {
                    searchPersonTaskbarButtonRectangle.border.color = "#313536"
                    addPersonTaskbarButtonRectangle.border.color = "#F4F4F4"
                    deletePersonTaskbarButtonRectangle.border.color = "#313536"
                    modifyPersonTaskbarButtonRectangle.border.color = "#313536"
                }

                Rectangle {
                    id: addPersonTaskbarButtonRectangle
                    anchors.fill: parent
                    color: "#535A5C"
                    border.width: 1
                    border.color: "#313536"
                    radius: 15

                    Text{
                        id: addPersonTaskbarButtonText
                        text: "Add Person"
                        font.family: "Titillium Web"
                        font.pointSize: 13
                        anchors.centerIn: parent
                        color: "White"
                    }
                }
            }
            RoundButton{
                id: deletePersonTaskbarButton
                width: taskbarLeft.width
                height: 50
                onClicked: {
                    searchPersonTaskbarButtonRectangle.border.color = "#313536"
                    addPersonTaskbarButtonRectangle.border.color = "#313536"
                    deletePersonTaskbarButtonRectangle.border.color = "#F4F4F4"
                    modifyPersonTaskbarButtonRectangle.border.color = "#313536"
                }
                
                Rectangle {
                    id: deletePersonTaskbarButtonRectangle
                    anchors.fill: parent
                    color: "#535A5C"
                    border.width: 1
                    border.color: "#313536"
                    radius: 15

                    Text{
                        id: deletePersonTaskbarButtonText
                        text: "Delete Person"
                        font.family: "Titillium Web"
                        font.pointSize: 13
                        anchors.centerIn: parent
                        color: "White"
                    }
                }
            }
            RoundButton{
                id: modifyPersonTaskbarButton
                width: taskbarLeft.width
                height: 50
                onClicked: {
                    searchPersonTaskbarButtonRectangle.border.color = "#313536"
                    addPersonTaskbarButtonRectangle.border.color = "#313536"
                    deletePersonTaskbarButtonRectangle.border.color = "#313536"
                    modifyPersonTaskbarButtonRectangle.border.color = "#F4F4F4"
                }

                Rectangle {
                    id: modifyPersonTaskbarButtonRectangle
                    anchors.fill: parent
                    color: "#535A5C"
                    border.width: 1
                    border.color: "#313536"
                    radius: 15

                    Text{
                        id: modifyPersonTaskbarButtonText
                        text: "Modify Person"
                        font.family: "Titillium Web"
                        font.pointSize: 13
                        anchors.centerIn: parent
                        color: "White"
                    }
                }
            }
        }
    }

    Rectangle {
        id: logo
        color: "#DCE3E4"
        width: taskbarLeft.width
        height: taskbarTop.height
        anchors.left: originalWindow.left
        anchors.top: originalWindow.top
        
        Text {
            id: logoText
            text: "Phone Book"
            font.family: "Titillium Web"
            font.pointSize: 20
            font.bold: true
            anchors.centerIn: logo
        }
    }
}