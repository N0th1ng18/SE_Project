import QtQuick 2.12

import QtQuick.Controls 2.5

Item {

    id: menuPg


    ToolBar{

        id: tbar

        width: menuPg.width

        height: contentHeight

        Rectangle{

            anchors.fill: parent
        }

        ToolButton{

            id: toolbutton

            width: menuConn.getToolBtnWidth()

            height: menuConn.getToolBtnHeight()

            text: "\u2630"

            font.pixelSize: menuConn.getBtnFontSize()


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

         width: 0.66 * menuPg.width

         height: menuPg.height * 0.80


       Column{

           anchors.fill: parent


           ItemDelegate{

               width: parent.width

               text: qsTr("Host Game")

               font.pixelSize: menuConn.getDelFontSize()


               onClicked: {
                  if(menuStack.depth > 1)
                      stack.pop()

                   menuStack.push("hostgame.qml")
                   optionsPanel.close();
               }

           }


           ItemDelegate{

               width: parent.width

               text: qsTr("Join Game")

               font.pixelSize: menuConn.getDelFontSize()


               onClicked: {
                   if(menuStack.depth > 1)
                       stack.pop()

                    menuStack.push("joingame.qml")
                    optionsPanel.close()
               }

           }

           ItemDelegate{

               width: parent.width

               text: qsTr("User Lobby")

               font.pixelSize: menuConn.getDelFontSize()

              onClicked: {
                  if(menuStack.depth > 1)
                      stack.pop()

                    menuStack.push("resumegame.qml")
                    optionsPanel.close()
              }

           }


           ItemDelegate{

               width: parent.width

               text: qsTr("Settings")

               font.pixelSize: menuConn.getDelFontSize()

              // onClicked: {}

           }


           ItemDelegate{

               width: parent.width

               text: qsTr("Logout")

               font.pixelSize: menuConn.getDelFontSize()

               onClicked: {

                   optionsPanel.close()

                   menuConn.pop()

                   menuConn.clear()

                   loginConn.push();
               }

           }

       }

    }

    StackView{

        id: menuStack
         initialItem: "resumegame.qml"
        anchors.fill: parent

    }

 }

