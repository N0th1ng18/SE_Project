import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: createAccountPg

    Column{
        anchors.centerIn: parent
        width: implicitWidth
        height: implicitHeight

        spacing: 20

        Label{
            text: "Enter your desired username and password"
        }

        TextField{
            id: username
            objectName: "usernamefield"
            width: implicitWidth
            height: implicitHeight
            maximumLength: 20
            placeholderText: "Username"
            property bool nameStatus

          }



        TextField{
            id: passwordField
            objectName: "passwordfield"
            width: implicitWidth
            height: implicitHeight
            maximumLength: 20
            placeholderText: "Password"
        }


        Button{
            width: implicitWidth
            text: "Create Account"
        }
    }
}
