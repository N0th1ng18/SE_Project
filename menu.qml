import QtQuick 2.12
import QtQuick.Controls 2.5
Item {

    id: menuLobby

    ToolBar{

        Rectangle{
            anchors.fill: parent
            color: "whitesmoke"
        }

        contentHeight: toolbutton.implicitHeight
        width: parent.width
        ToolButton{
            id: toolbutton
            text: "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6

            onClicked: {
                if(menuStack.depth > 1){
                    menuStack.clear()
                    optionsPanel.open()
                }
                else{
                    optionsPanel.open()
                }

            }
        }

    }

    Drawer{
        id: optionsPanel
        edge: Qt.TopEdge
         width: 0.66 * menuLobby.width
         height: menuLobby.height

       Column{
           anchors.fill: parent

           ItemDelegate{
               width: parent.width
               text: qsTr("Host Game")

               onClicked: {
                   menuStack.push("hostgame.qml")
                   optionsPanel.close()
               }
           }

           ItemDelegate{
               width: parent.width
               text: qsTr("Join Game")

               onClicked: {
                   menuStack.push("joingame.qml")
                   optionsPanel.close()
               }

           }

           ItemDelegate{
               width: parent.width
               text: qsTr("Resume Session")

               onClicked: {
                    menuStack.push("resumegame.qml")
                   optionsPanel.close()
               }
           }


           ItemDelegate{
               width: parent.width
               text: qsTr("Settings")

               onClicked: {
                    // yet to be implemented
               }
           }

           ItemDelegate{
               width: parent.width
               text: qsTr("Logout")

               onClicked: {
                   optionsPanel.close()
                   menuConn.pop()
                   menuConn.clear()
                   homeConn.push();

               }
           }
       }
    }

    StackView{
        id: menuStack
        anchors.fill: parent
    }


 }

