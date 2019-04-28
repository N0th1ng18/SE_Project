import QtQuick 2.0
import QtQuick.Controls 2.5

Item {

    Column{
        id: prevSessions
        anchors.centerIn: parent
        spacing: 30

        Repeater{
            model: 3
            Row{

               anchors.horizontalCenter: parent.horizontalCenter
               spacing: 15
               Label{
                   text: qsTr("room code")
                   font.pointSize: fontSize
                   anchors.verticalCenter: parent.verticalCenter

               }

               Button{
                   text: qsTr("resume")
                   font.pointSize: fontSize
                   width: buttonWidth * .8
                   height: buttonHeight * .8

               }

               Button{
                   text: qsTr("delete")
                   font.pointSize: fontSize
                   width: buttonWidth * .8
                   height: buttonHeight *.8
               }
            }
        }

    }
}
