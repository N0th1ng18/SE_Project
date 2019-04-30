import QtQuick 2.0

import QtQuick.Controls 2.5



Item {

    id: joinGamePg


    Column{

        anchors.centerIn: parent

        spacing: 40

        Label{

            text:  qsTr("Enter Room Code")

            color: "whitesmoke"

            anchors.horizontalCenter: parent.horizontalCenter

            font.pixelSize: menuConn.getLbFontSize()

        }

        TextField{
            id: room

            anchors.horizontalCenter: parent.horizontalCenter

            width: menuConn.getTextFieldWidth()

            height: menuConn.getTextFieldHeight()

            font.pixelSize: menuConn.getTfFontSize()

            placeholderText: "Room Code"

        }

        Button{
            property int status: 0
            anchors.horizontalCenter: parent.horizontalCenter

            width: menuConn.getBtnWidth()

            height: menuConn.getBtnHeight()

            font.pixelSize: menuConn.getBtnFontSize()

            text: qsTr("Join")

            onClicked: {
                status = clientprotocol.sendJoinGame(room.text);

                switch(status){
                case 0:
                   joinStatusReport.text = "Invalid room code"
                    joinStatusReport.visible = true
                    break;
                case 1:
                    // pass address and port to GameRenderer
                    break;
                case 2:
                    joinStatusReport.text = "No server available"
                    joinStatusReport.visible = true
                }
            }

        }

        Label{
            id: joinStatusReport
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            color: "red"
            font.pixelSize: menuConn.getLbFontSize()
            onFocusChanged: {
                visible = false
            }
        }
    }

}
