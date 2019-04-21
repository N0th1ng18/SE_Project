import QtQuick 2.0
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
              width: implicitWidth + (implicitWidth * createAccountPg.width * .001)
              height: implicitHeight + (implicitHeight * createAccountPg.height * .001)
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
            font.pixelSize: 30 + ( createAccountPg.width/ createAccountPg.height)
        }

        TextField{
            id: usernameField

            anchors.horizontalCenter: parent.horizontalCenter
            width: implicitWidth + (implicitWidth * createAccountPg.width/createAccountPg.height)
            height: implicitHeight + (implicitHeight * createAccountPg.height/createAccountPg.width)
            maximumLength: 20
            placeholderText: "Username"
            property bool nameStatus

          }



        TextField{
            id: passwordField

            anchors.horizontalCenter: parent.horizontalCenter
            width: implicitWidth + (implicitWidth * createAccountPg.width/createAccountPg.height)
            height: implicitHeight + (implicitHeight * createAccountPg.height/createAccountPg.width)
            maximumLength: 20
            placeholderText: "Password"
        }


        Button{
            anchors.horizontalCenter: parent.horizontalCenter
            width: usernameField.width * .67
            height: usernameField.height * 0.65
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
