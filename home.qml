import QtQuick 2.0
import QtQuick.Controls 2.5

Item {


    Column{
        id: homeFocus
        spacing: 20
        width: implicitWidth
        height: implicitHeight
        anchors.centerIn: parent

        Label{

            anchors.horizontalCenter: parent.horizontalCenter
            text: "Home Screen"
            font.bold: true
            font.pixelSize: 30
        }

        Row{

            spacing: 10


            Button{
                id: loginButton

                width: 150
                height: 75
                text: "Login Menu"
                font.pixelSize: 20

                onClicked: {
                    loginConn.push()
                }

            }

            Button{
                id: gameButton

                width: 150
                height: 75
                text: "Game Menu"
                font.pixelSize: 20

                onClicked: {
                    menuConn.push()
                }

            }
        }

    }
}
