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

            width: toolButtonWidth

            height: toolButtonHeight

            text: "\u2630"

            font.pointSize: fontSize


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

               font.pointSize: fontSize


               onClicked: {

                   menuStack.push("hostgame.qml")

                   optionsPanel.close()

               }

           }


           ItemDelegate{

               width: parent.width

               text: qsTr("Join Game")

               font.pointSize: fontSize


               onClicked: {

                   menuStack.push("joingame.qml")

                   optionsPanel.close()

               }

           }

           ItemDelegate{

               width: parent.width

               text: qsTr("User Lobby")

               font.pointSize: fontSize

               onClicked: {

                    menuStack.push("resumegame.qml")

               }

           }


           ItemDelegate{

               width: parent.width

               text: qsTr("Settings")

               font.pointSize: fontSize

               onClicked: {

                    // yet to be implemented

               }

           }


           ItemDelegate{

               width: parent.width

               text: qsTr("Logout")

               font.pointSize: fontSize

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
        initialItem: "resumegame.qml"
    }

 }
