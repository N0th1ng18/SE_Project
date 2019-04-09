import QtQuick 2.0
import QtQuick.Controls 2.5

Item{
    id: loginPg

   Column{
        id: column
        width: implicitWidth
        height: implicitHeight
        spacing: 20
        anchors.centerIn: parent

       TextField{
           id: usernameField
           objectName: "usernamefield"
           width: implicitWidth
           height: implicitHeight
           maximumLength: 20
           placeholderText: "Username"
       }

       TextField{
           id: passwordField
           objectName: "passwordfield"
           width: implicitWidth
           height: implicitHeight
           maximumLength: 20
           placeholderText: "Password"
       }
    }

   Button{
           id: submit
           anchors.top: column.bottom
           anchors.left: column.left
           anchors.topMargin: 25
           text: "Submit"

           onClicked: {
               playerinfo.receiveUsername(usernameField.text)
               playerinfo.receivePassword(passwordField.text)
           }
       }

}

