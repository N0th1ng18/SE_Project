#include "widget.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>
#include <QScreen>
#include "clientprotocol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);


    QScreen *screen = QApplication::screens().at(0);
    int screenWidth = screen->availableSize().width();
    int screenHeight = screen->availableSize().height();

    qDebug() << "Window:\n";
    qDebug() << "AvailScreen(" << screenWidth << ", " << screenHeight << ")";


    Widget window;
    //window.setWindowState(Qt::WindowFullScreen);
    window.show();

    //ClientProtocol::connectMainServer();

    return a.exec();
}
