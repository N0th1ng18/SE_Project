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


    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(3, 0);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);


    QScreen *screen = QApplication::screens().at(0);
    int screenWidth = screen->availableSize().width();
    int screenHeight = screen->availableSize().height();

    qDebug() << "Window:\n";
    qDebug() << "ScreenRes("<< screenWidth << ", " << screenHeight << ")";


    Widget window;
    //window.setWindowState(Qt::WindowFullScreen);
    window.show();
    window.hide();

    OpenGLWindow glWindow;
    //glWindow.setWindowState(Qt::WindowFullScreen);
    glWindow.show();

    //ClientProtocol::connectMainServer();

    return app.exec();
}
