import QtQuick 2.0

import QtQuick.Controls 2.5



Item {

    id: hostGamePg
    anchors.fill: parent;

     Column{

         anchors.centerIn: parent

         spacing: 30



         //Extremely minimal



         Label{

             // Will receive a valid room code from database

             text: qsTr("XXXX")

             font.pixelSize: 30 + (15 * hostGamePg.width/ hostGamePg.height)

             font.bold: true

             anchors.horizontalCenter: parent.horizontalCenter

         }

     }

}
