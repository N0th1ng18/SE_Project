import QtQuick 2.0

import QtQuick.Controls 2.5



Item{

    id: loginPg





  ToolBar{

        id: loginPageToolBar



        height: contentHeight

        width: parent.width

        Rectangle{

            anchors.fill: parent

            color: "whitesmoke"



        }



        ToolButton{

            anchors.right: parent.right

            text: "Create Account"

            onClicked: {

                createAccountConn.push()

            }

        }



        ToolButton{

            anchors.left: parent.left

            text: "Previous"

            onClicked: {

                loginConn.pop()

            }

        }



  }



   Column{

        id: column

        width: implicitWidth

        height: implicitHeight

        spacing: 20

        anchors.centerIn: parent



       TextField{

           id: usernameField



           anchors.horizontalCenter: parent.horizontalCenter

           width: implicitWidth

           height: implicitHeight

           maximumLength: 20

           placeholderText: "Username"

       }



       TextField{

           id: passwordField



           anchors.horizontalCenter: parent.horizontalCenter

           width: implicitWidth

           height: implicitHeight

           maximumLength: 20

           placeholderText: "Password"

       }

    }



   Button{

           id: submit



           anchors.horizontalCenter: parent.horizontalCenter

           anchors.top: column.bottom

           anchors.left: column.left

           anchors.topMargin: 25

           text: "Submit"



           onClicked: {

              /* Functionality Incomplete

                  must query database for

                  playerinfo



                  if user found then

                    login

                  else

                    inform user of erro

                  end if

              */

              menuConn.push()

           }

       }



}
