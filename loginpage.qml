import QtQuick 2.0
import QtQuick.Controls 2.5

Item{
    id: loginPg
    enabled: false

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
            width: implicitWidth + (implicitWidth * loginPg.width * .001)
            height: implicitHeight + (implicitHeight * loginPg.height * .001)
            text: "Create Account"
            onClicked: {
                createAccountConn.push()
            }
        }

        ToolButton{
            anchors.left: parent.left
            width: implicitWidth + (implicitWidth * loginPg.width * .001)
            height: implicitHeight + (implicitHeight * loginPg.height * .001)
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
           width: implicitWidth + (implicitWidth * loginPg.width/loginPg.height)
           height: implicitHeight + (implicitHeight * loginPg.height/loginPg.width)
           maximumLength: 20
           placeholderText: "Username"
       }

       TextField{
           id: passwordField

           anchors.horizontalCenter: parent.horizontalCenter
           width: implicitWidth + (implicitWidth * loginPg.width/loginPg.height)
           height: implicitHeight + (implicitHeight * loginPg.height/loginPg.width)
           maximumLength: 20
           placeholderText: "Password"
       }
    }

   Button{
           id: submit

           anchors.horizontalCenter: parent.horizontalCenter
           anchors.top: column.bottom
           anchors.left: column.left
           width: implicitWidth + (implicitWidth * loginPg.height/loginPg.width)
           height: implicitHeight + (implicitHeight * loginPg.height/loginPg.width)
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
               clientprotocol.sendUserLogin(usernameField.text,passwordField.text)
              // clientprotocol.sendJoinGame(29)
              menuConn.push()
           }
       }

   Text{
       id: connStatus

       anchors.bottom: parent.bottom;
       text: qsTr("Connecting to server...");
       font.pixelSize: 15 + (15 + parent.height/parent.width * .33);

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
}

