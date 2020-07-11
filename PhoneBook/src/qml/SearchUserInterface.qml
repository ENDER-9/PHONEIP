import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4



Rectangle {
    id: root
    width: 500
    height: 500
    color: "#313536"



    RowLayout {
        anchors.topMargin: 30
        height: 50
        width: parent.width / 2
        anchors.top: root.top
        anchors.horizontalCenter: root.horizontalCenter

        TextField {
            height: 40
            id: inputFirstNameTextField
            placeholderText: qsTr("Enter first name")
        
        }   

        TextField {
            height: 40
            id: inputLastNameTextField
            placeholderText: qsTr("Enter last name")
        }
        RoundButton {
            width: 200
            height: 40
            highlighted: true
            onClicked: {

            }

            Rectangle {
                width: 100
                height: 40
                color: "#F4F4F4"
                radius: 15


                Text {
                    text: qsTr("Search")
                    anchors.centerIn: parent
                }
            }
        }
    }
}