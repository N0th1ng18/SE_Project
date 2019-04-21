import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: homePg

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
            font.pixelSize: 30 + (15 * homePg.width/ homePg.height)
        }

        Row{

            spacing: 10


            Button{
                id: loginButton

                width: implicitWidth + (implicitWidth * homePg.width/ homePg.height)
                height: implicitHeight + (implicitHeight * homePg.height/homePg.width)
                text: "Login Menu"
                font.pixelSize: 20

                onClicked: {
                    loginConn.push()
                }

            }

            Button{
                id: gameButton

                width: loginButton.width
                height: loginButton.height
                text: "Game Menu"
                font.pixelSize: 20

                onClicked: {
                    menuConn.push()
                }

            }
        }

    }
}
