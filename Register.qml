import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.5





Item {

    id: createAccountPg

    ToolBar{

          id: createAccountPageToolBar

          width: createAccountPg.width

          height: contentHeight

          Rectangle{

              anchors.fill: parent

              color: "whitesmoke"



          }


          ToolButton{

              width: toolButtonWidth

              height: toolButtonHeight

              font.pointSize: fontSize

              anchors.left: parent.left

              text: "Previous"

              onClicked: {

                  createAccountConn.pop()

              }

          }

     }



    Column{

        anchors.centerIn: parent

        width: implicitWidth

        height: implicitHeight

        spacing: 20

        Label{

            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Enter your desired username and password")

            font.pointSize: fontSize

        }


        TextField{

            id: usernameField

            anchors.horizontalCenter: parent.horizontalCenter

            width: textFieldWidth

            height: textFieldHeight

           font.pointSize: fontSize + (height * .07)

            maximumLength: 20

            placeholderText: "Username"


          }


        TextField{

            id: passwordField

            anchors.horizontalCenter: parent.horizontalCenter

            width: textFieldWidth

            height: textFieldHeight

            font.pointSize: fontSize + (height * .07)

            maximumLength: 20

            placeholderText: "Password"

        }


        Button{

            anchors.horizontalCenter: parent.horizontalCenter

            width: buttonWidth

            height: buttonHeight

            text: "Create Account"

            font.pointSize: fontSize

            onClicked: {

                if(usernameField.text == ""){
                    playerInfoError.text = "You must enter at username"
                    playerInfoError.open()
                    return
                }

                if(passwordField.text == ""){
                    playerInfo.text = "You must enter a password"
                    playerInfo.open()
                    return
                }

                if(clientprotocol.sendPlayerInfo(0,usernameField.text,passwordField.text)){
                    createAccountConn.pop()
                }else{
                    playerInfoError.open()
                }

            }

        }

        MessageDialog{
             id: playerInfoError
             icon: StandardIcon.Warning

             title: qsTr("Login Error")
             text:  qsTr("Your username and password may contain invalid chararacter")
             onButtonClicked: {
                 usernameField.color = "red"
                 passwordField.color = "red"
             }
        }
    }

}
