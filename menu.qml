import QtQuick 2.12
import QtQuick.Controls 2.5
Item {


    Row{
        anchors.horizontalCenter: parent.center
        spacing: 25

        Button{
            width: 50
            height: 30
            text: "Host Game"
        }

        Button{
            width: 50
            height: 30
            text: "Join Game"
        }
    }
}
