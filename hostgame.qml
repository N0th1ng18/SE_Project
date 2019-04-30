import QtQuick 2.0

import QtQuick.Controls 2.5



Item {

    id: hostGamePg


     Column{


         anchors.centerIn: parent
         spacing: 30

         Label{
             id: hostCode       
            // Will receive a valid room code from database
            text: qsTr("Get Room Code")
            color: "whitesmoke"
            font.pixelSize: menuConn.getLbFontSize()
            anchors.horizontalCenter: parent.horizontalCenter

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(clientprotocol.sendCreateGame()){
                       // On success will set labels text to
                       // to given room code create label
                       // with room code
                       hostCode.text = clientprotocol.showRoomCode();
                    }else{
                       hostCode.text = qsTr("Error failed to create game")
                       hostCode.color = "red"
                    }
                }
                onFocusChanged: {
                    hostCode.text = qsTr("Get Room Code")
                    hostCode.color = "whitesmoke"
                }
            }

         }

     }

}
