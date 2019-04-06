#include "widget.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>
#include <QScreen>

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
    qDebug() << "X = " << screenWidth;
    qDebug() << "Y = " << screenHeight;


    Widget window;
    window.setWindowState(Qt::WindowFullScreen);
    window.showMaximized();

    return a.exec();
}
