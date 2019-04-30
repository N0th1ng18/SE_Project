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

              font.pixelSize: btnFontSize

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
            width: implicitWidth
            height: implicitHeight
            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Enter your desired username and password")

            textFormat: Text.WordWrap

            font.pixelSize: lbFontSize

            color: "whitesmoke"

        }


        TextField{

            id: usernameField

            anchors.horizontalCenter: parent.horizontalCenter

            width: textFieldWidth

            height: textFieldHeight

           font.pixelSize: tfFontSize

            maximumLength: 20

            placeholderText: "Username"

            onFocusChanged: {
                color = "black"
            }

        }


        TextField{

            id: passwordField

            anchors.horizontalCenter: parent.horizontalCenter

            width: textFieldWidth

            height: textFieldHeight

            font.pixelSize: tfFontSize

            maximumLength: 20

            placeholderText: "Password"

            onFocusChanged: {
                color = "black"
            }

        }


        Button{

            anchors.horizontalCenter: parent.horizontalCenter

            width: buttonWidth

            height: buttonHeight

            text: "Create Account"

            font.pixelSize: btnFontSize

            onClicked: {

                if(clientprotocol.sendCreateAccount(usernameField.text,passwordField.text)){
                    createAccountConn.pop()
                }else{
                    usernameField.color = "red"
                    passwordField.color = "red"
                }
            }

        }
    }

}
