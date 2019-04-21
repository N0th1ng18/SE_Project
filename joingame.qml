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

            font.pixelSize: 30 + (15 * joinGamePg.width/ joinGamePg.height)

        }



        TextField{

            anchors.horizontalCenter: parent.horizontalCenter

            width: implicitWidth + (implicitWidth * joinGamePg.width/ joinGamePg.height)

            height: implicitHeight + (implicitHeight * joinGamePg.height/joinGamePg.width)

            placeholderText: "Room Code"

            maximumLength: 4



        }



        Button{

            anchors.horizontalCenter: parent.horizontalCenter

            width: implicitWidth + (implicitWidth * joinGamePg.width/ joinGamePg.height)

            height: implicitHeight + (implicitHeight * joinGamePg.height/joinGamePg.width)

            text: qsTr("Join")

            onClicked: {

                mainConn.hide()

                GameRenderer.launchGame()

            }

        }

    }

}
