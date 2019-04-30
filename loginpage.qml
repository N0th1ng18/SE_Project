import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.5

Item{
    id: loginPg
    //enabled: false

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
            font.pixelSize: btnFontSize
            width: toolButtonWidth
            height: toolButtonHeight
            text: "Create Account"

            onClicked: {
                createAccountConn.push()
            }
        }

  }

   Column{
        id: column

        spacing: 20
        anchors.centerIn: parent

       TextField{
           id: usernameField
           anchors.horizontalCenter: parent.horizontalCenter
           font.pixelSize: tfFontSize
           width: textFieldWidth
           height: textFieldHeight
           maximumLength: 20
           placeholderText: "Username"

           onFocusChanged:{

               color = "black"
            }
       }

       TextField{
           id: passwordField
           font.pixelSize: tfFontSize
           anchors.horizontalCenter: parent.horizontalCenter
           echoMode: TextInput.PasswordEchoOnEdit
           width: textFieldWidth
           height: textFieldHeight
           maximumLength: 20
           placeholderText: "Password"


           onFocusChanged:{

               color = "black"
          }
       }
    }

   Button{
           id: submit
           anchors.horizontalCenter: parent.horizontalCenter
           anchors.top: column.bottom
           font.pixelSize: btnFontSize
           width: buttonWidth
           height: buttonHeight
           anchors.topMargin: 25
           text: "Login"

           onClicked: {
               clientprotocol.size = clientprotocol.sendUserLogin(usernameField.text,passwordField.text)
                if(clientprotocol.size !== 0){
                    menuConn.push()
                }else{
                    mainConn.errMsg("hello");

                    usernameField.color = "red"
                    passwordField.color = "red"

                    // The user login has failed
                    // implement error handling message
                }
           }
       }

   Text{
       id: connStatus

       anchors.bottom: parent.bottom;
       text: qsTr("Connecting to server...");
       font.pixelSize: lbFontSize

       Component.onCompleted: {
           if(clientprotocol.connectToServer()){
               text = qsTr("Connection Successful")

               loginPg.enabled = true;
           }else{

               text = qsTr("Failed to connect to server")
               connStatus.color = "red"
           }
       }

   }


}

