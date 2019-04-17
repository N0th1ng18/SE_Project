import QtQuick 2.0
import QtQuick.Controls 2.5


Item {
    id: createAccountPg


    ToolBar{
          id: createAccountPageToolBar

          height: contentHeight
          width: parent.width
          Rectangle{
              anchors.fill: parent
              color: "whitesmoke"

          }


          ToolButton{
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
            text: "Enter your desired username and password"
        }

        TextField{
            id: username

            anchors.horizontalCenter: parent.horizontalCenter
            width: implicitWidth
            height: implicitHeight
            maximumLength: 20
            placeholderText: "Username"
            property bool nameStatus

          }



        TextField{
            id: passwordField

            anchors.horizontalCenter: parent.horizontalCenter
            width: implicitWidth
            height: implicitHeight
            maximumLength: 20
            placeholderText: "Password"
        }


        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            width: implicitWidth
            text: "Create Account"

            onClicked: {
                /*
                   Funtionality incomplete

                   if playerinfo exists then
                        inform user/ try again
                   else
                        update database
                        return to login page
                   end if
                */
                createAccountConn.pop()
            }
        }
    }
}
