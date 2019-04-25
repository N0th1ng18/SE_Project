import QtQuick 2.0

import QtQuick.Controls 2.5



Item {

    id: resumeGamePg
    anchors.fill: parent



    Column{

        id: roomCodeContainer

        anchors.centerIn: parent

        spacing: 20



        Repeater{

            id: loop

            model: 5



            Label{

                anchors.horizontalCenter: roomCodeContainer.horizontalCenter

                text:  qsTr("Fetched room code")

                font.pixelSize: 30 + (15 * resumeGamePg.width/ resumeGamePg.height)

            }

        }



    }

}
