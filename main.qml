import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
//import "loginpage.qml"

ApplicationWindow{
    id: mainView
    visible: true
    width: 720
    height: 1080

    property real buttonWidth: Screen.desktopAvailableWidth * .3
    property real buttonHeight: Screen.desktopAvailableHeight * .2
    property real toolButtonWidth: Screen.desktopAvailableWidth * .2
    property real toolButtonHeight: Screen.desktopAvailableHeight * .15
    property real textFieldWidth: Screen.desktopAvailableWidth * .4
    property real textFieldHeight: Screen.desktopAvailableHeight * .25
    property real fontSize: 20 + Screen.desktopAvailableHeight/Screen.desktopAvailableWidth

    /******************

        The following connections are a means of communications
        between Abstract Data Types as well as well as seperate Qml
        files

    ******************/

    // Abstact Data Type Connections

    Connections{
        id: clientConn
        target: clientprotocol
    }

    Connections{
        // Connects PlayerInfo Class
        id: playerConn
        target: playerinfo
    }

    Connections{
        // Connects GameRenderer Class
        id: gameRendererConn
        target: GameRenderer

        onBeginExit:{
            mainConn.visible = true
        }
    }

    // Connects Qml files

    Connections{
        id: mainConn

        function hide(){
            mainView.visible = false
        }
    }

    Connections{
        id: homeConn
        target: stack.currentItem

        function push(){
            stack.push("home.qml")
        }

        function pop(){
            stack.pop()
        }
    }

    Connections{
        id: loginConn
        target: stack.currentItem

        function push(){
            stack.push("loginpage.qml")
        }

        function pop(){
            stack.pop()
        }
    }

    Connections{

        id: menuConn
        target: stack.currentItem

        function push(){
            stack.push("menu.qml")
        }

        function pop(){
            stack.pop()
        }

        function clear(){
            stack.clear()
        }
    }

    Connections{
        id: createAccountConn
        target: stack.currentItem

        function push(){
            stack.push("register.qml")
        }

        function pop(){
            stack.pop()
        }
    }

    Image{
        width: Screen.desktopAvailableWidth
        height: Screen.desktopAvailableHeight
        fillMode: Image.PreserveAspectCrop
       source: "qrc:/The_Jungle_Book.jpg"
    }



    StackView{
        id: stack
        initialItem: "loginpage.qml"
        anchors.fill: parent

    }
}
