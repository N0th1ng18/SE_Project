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
            font.pointSize: fontSize
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
           font.pointSize: fontSize + (height * .07)
           width: textFieldWidth
           height: textFieldHeight
           maximumLength: 20
           placeholderText: "Username"
           onFocusChanged: {
               color = "black"
           }

       }

       TextField{
           id: passwordField
           font.pointSize: fontSize + (height * .07)
           anchors.horizontalCenter: parent.horizontalCenter
           echoMode: TextInput.PasswordEchoOnEdit
           width: textFieldWidth
           height: textFieldHeight
           maximumLength: 20
           placeholderText: "Password"
           onFocusChanged: color = "black"
       }
    }

   Button{
           id: submit

           anchors.horizontalCenter: parent.horizontalCenter
           anchors.top: column.bottom
           font.pointSize: fontSize
           width: buttonWidth
           height: buttonHeight
           anchors.topMargin: 25
           text: "Login"

           onClicked: {
                if(usernameField.text == ""){
                    playerInfoError.text = "Enter a username!"
                    playerInfoError.open()
                    return
                }
                if(passwordField.text == ""){
                    playerInfoError.text = "Enter a password!"
                    playerInfoError.open();
                    return
                }

                if(clientprotocol.sendUserLogin(usernameField.text,passwordField.text)){
                    menuConn.push()
                }else{
                    playerInfoError.open()
                }
           }
       }

   Text{
       id: connStatus

       anchors.bottom: parent.bottom;
       text: qsTr("Connecting to server...");
       font.pointSize: fontSize

       Component.onCompleted: {
           if(clientprotocol.connectToServer()){
               text = qsTr("Connection Successful")
               connStatus.color = "green"
               loginPg.enabled = true;
           }else{
               text = qsTr("Failed to connect to server")
                connStatus.color = "red"
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

