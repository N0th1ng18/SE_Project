

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QtDebug>
#include <QSurfaceFormat>
#include <QScreen>

#include "playerinfo.h"
#include "clientprotocol.h"
#include "openglwindow.h"
#include "gamerenderer.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Connect to Main Server
    ClientProtocol* cp = new ClientProtocol();
    QTcpSocket* socket = cp->connectMainServer();

    //Send Message
    if(socket != nullptr){
        qDebug("Connected!");

        float f = 10.01f;
        int d = 5;

        //Message Seperator = |
        //Message Ender     = ||

        //Load QString
        QString s = "0|";
        s.append(QString::number(f));

        //Append QString to QByteArray
        QByteArray array;
        array.append(s);

        //Write To Socket
        socket->write(array);
        socket->write(array);
        socket->flush();
    }







    //QSurfaceFormat for opengl context
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(2, 0);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    /*************************************************************************/

    PlayerInfo player;
    //OpenGL Window
    OpenGLWindow glWindow;

    QQmlEngine engine;
    QQmlComponent *component = new QQmlComponent(&engine);
    QQmlContext *ctx = engine.rootContext();
    QObject * topLevel;
    GameRenderer *gameView = new GameRenderer(&glWindow);
    ctx->setContextProperty("playerinfo", &player);
    ctx->setContextProperty("GameRenderer", gameView);

    component->loadUrl(QStringLiteral("qrc:/main.qml"));

    topLevel = component->create();

    app.exec();
    qDebug() << player.getUsername() << " " << player.getPassword() << endl;


    /*************************************************************************/

    socket->disconnectFromHost();

    return 0;
}
