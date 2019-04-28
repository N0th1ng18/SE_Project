import QtQuick 2.0

import QtQuick.Controls 2.5



Item {

    id: joinGamePg


    Column{

        anchors.centerIn: parent

        spacing: 40


        Label{

            text:  qsTr("Enter Room Code")

            anchors.horizontalCenter: parent.horizontalCenter

            font.pointSize: fontSize

        }



        TextField{

            anchors.horizontalCenter: parent.horizontalCenter

            width:textFieldWidth

            height: textFieldHeight

            font.pointSize: fontSize + (height * .07)

            placeholderText: "Room Code"

            maximumLength: 4

        }



        Button{

            anchors.horizontalCenter: parent.horizontalCenter

            width: buttonWidth

            height: buttonHeight

            font.pointSize: fontSize

            text: qsTr("Join")

            onClicked: {

                mainConn.hide()

                GameRenderer.launchGame()

            }

        }

    }

}
