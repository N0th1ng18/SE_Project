import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

ApplicationWindow{
    visible: true
    width: 640
    height: 480

    Connections{
        id: playerConn
        target: playerinfo
    }

    Rectangle{
        color: "#f5e6ae"
        anchors.fill: parent
    }

    header: ToolBar{
        id: tbar

       ToolButton{
           id: registerButton
           objectName: "registerBtn"
           text: "Create Account"
           anchors.right: parent.right
           onClicked: {
               if (stack.depth < 2){
                    stack.push("register.qml")
               }
           }
       }

       ToolButton{
           id: backButton
           text: "<"
           anchors.left: parent.left
           onClicked:{
               if(stack.depth > 1){
                    stack.pop()
               }
           }
       }
    }


    StackView{
        id: stack
        initialItem: "loginpage.qml"
        anchors.fill: parent
    }
}
