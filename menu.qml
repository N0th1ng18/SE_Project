import QtQuick 2.12

import QtQuick.Controls 2.5

Item {



    id: menuPg
    anchors.fill: parent


    ToolBar{

        id: tbar

        width: menuPg.width

        height: contentHeight



        Rectangle{

            anchors.fill: parent



        }



        ToolButton{

            id: toolbutton

            width: implicitWidth + (implicitWidth * menuPg.width/ menuPg.height)

            height: implicitHeight + (implicitHeight * menuPg.width/menuPg.height)

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

         width: 0.66 * menuPg.width

         height: menuPg.height * 0.80





       Column{

           anchors.fill: parent



           ItemDelegate{

               width: parent.width

               text: qsTr("Host Game")

               font.pixelSize: 12 + (menuPg.height * 0.0275)



               onClicked: {

                   menuStack.push("hostgame.qml")

                   optionsPanel.close()

               }

           }



           ItemDelegate{

               width: parent.width

               text: qsTr("Join Game")

               font.pixelSize: 12 + (menuPg.height * 0.0275)



               onClicked: {

                   menuStack.push("joingame.qml")

                   optionsPanel.close()

               }



           }



           ItemDelegate{

               width: parent.width

               text: qsTr("Resume Session")

               font.pixelSize: 12 + (menuPg.height * 0.0275)



               onClicked: {

                    menuStack.push("resumegame.qml")

                   optionsPanel.close()

               }

           }





           ItemDelegate{

               width: parent.width

               text: qsTr("Settings")

               font.pixelSize: 12 + (menuPg.height * 0.0275)



               onClicked: {

                    // yet to be implemented

               }

           }



           ItemDelegate{

               width: parent.width

               text: qsTr("Logout")

               font.pixelSize: 12 + (menuPg.height * 0.0275)



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
