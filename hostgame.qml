import QtQuick 2.0

import QtQuick.Controls 2.5



Item {

    id: hostGamePg


     Column{

         anchors.centerIn: parent

         spacing: 30

         //Extremely minimal

         Label{

             // Will receive a valid room code from database

             text: qsTr("XXXX")

             font.pointSize: fontSize * (height * .07)

             font.bold: true

             anchors.horizontalCenter: parent.horizontalCenter

         }

         Component.onCompleted: {
             clientprotocol.sendCreateGame();
         }

     }

}
