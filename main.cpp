

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

    QQmlEngine engine;
    QQmlComponent *component = new QQmlComponent(&engine);
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("playerinfo", &player);

    component->loadUrl(QStringLiteral("qrc:/main.qml"));

    QObject * topLevel = component->create();

    int r = app.exec();
    qDebug() << player.getUsername() << " " << player.getPassword() << endl;

    //OpenGL Window
    OpenGLWindow glWindow;
    //glWindow.setWindowState(Qt::WindowFullScreen);
   // glWindow.show();
    /*************************************************************************/


    //ClientProtocol::connectMainServer();

    return 0;
}
