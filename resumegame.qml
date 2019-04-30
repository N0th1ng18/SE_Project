import QtQuick 2.0
import QtQuick.Controls 2.5

Item {

    Column{
        id: prevSessions
        anchors.centerIn: parent
        spacing: 30
        property int index: 2
        Repeater{
            id: loop
            model: clientprotocol.size
            Row{

               anchors.horizontalCenter: parent.horizontalCenter
               spacing: 15
               Label{
                   color: "whitesmoke"
                   text: qsTr(clientprotocol.loginDataProcess(index))
                   font.pixelSize: menuConn.getLbFontSize()
                   anchors.verticalCenter: parent.verticalCenter

               }

               Button{
                   text: qsTr("resume")
                   font.pixelSize: menuConn.getBtnFontSize()
                   width: menuConn.getBtnWidth()
                   height: menuConn.getBtnHeight()

                   onClicked: {
                       // resume desired
                   }
               }

               Button{
                   text: qsTr("delete")
                   font.pixelSize: menuConn.getBtnFontSize()
                   width: menuConn.getBtnWidth()
                   height: menuConn.getBtnHeight()

                   onClicked: {
                       // Deleted desired game

                   }
               }

            }

        }

    }
}
