import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5


ApplicationWindow{
    id: mainView
    visible: true
    width: 720
    height: 1080



    property real buttonWidth: Screen.desktopAvailableWidth * .125
    property real buttonHeight: Screen.desktopAvailableHeight * .085
    property real toolButtonWidth: Screen.desktopAvailableWidth * .125
    property real toolButtonHeight: Screen.desktopAvailableHeight * .085
    property real textFieldWidth: Screen.desktopAvailableWidth * .15
    property real textFieldHeight: Screen.desktopAvailableHeight * .085


    property real fontSize: 20 + Screen.desktopAvailableHeight/Screen.desktopAvailableWidth
    property real tfFontSize: fontSize + 15
    property real btnFontSize: fontSize + 10
    property real lbFontSize: fontSize + 18
    property real delFontSize: fontSize + 12

    /******************

        The following connections are a means of communications
        between Abstract Data Types as well as well as seperate Qml
        files

    ******************/

    // Abstact Data Type Connections


    Connections{
        id: clientConn
        target: clientprotocol
        property int size
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

        function errMsg(msg){

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

        function getFontSize(){
            return fontSize
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

        function getFontSize(){
            return fontSize
        }

        function getBtnWidth(){
            return buttonWidth
        }

        function getBtnHeight(){
            return buttonHeight
        }

        function getToolBtnWidth(){
            return toolButtonWidth
        }

        function getToolBtnHeight(){
            return toolButtonHeight
        }

        function getTextFieldWidth(){
            return textFieldWidth
        }

        function getTextFieldHeight(){
            return textFieldHeight
        }

        function getTfFontSize(){
            return tfFontSize
        }

        function getBtnFontSize(){
            return btnFontSize
        }

        function getLbFontSize(){
           return lbFontSize
        }

        function getDelFontSize(){
            return delFontSize
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


/*
    Image{
        width: Screen.desktopAvailableWidth
        height: Screen.desktopAvailableHeight
        fillMode: Image.PreserveAspectCrop
       source: "qrc:/The_Jungle_Book.jpg"
    }

*/

    Rectangle{
        color: "#586f47"
        anchors.fill: parent
        border.color: "#00e48c8c"
    }

    StackView{
        id: stack
        initialItem: "loginpage.qml"
        anchors.fill: parent

    }
}
