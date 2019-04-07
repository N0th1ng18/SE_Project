#include "widget.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>
#include <QScreen>
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

    //UI Window
    Widget window;
    //window.setWindowState(Qt::WindowFullScreen);
    window.show();
    window.hide();
    /*************************************************************************/

    //OpenGL Window
    OpenGLWindow glWindow;
    //glWindow.setWindowState(Qt::WindowFullScreen);
    glWindow.show();
    /*************************************************************************/


    //ClientProtocol::connectMainServer();

    return app.exec();
}
