

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


    //ClientProtocol::connectMainServer();

    return 0;
}
