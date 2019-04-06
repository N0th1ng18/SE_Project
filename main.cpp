#include "widget.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDebug>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScreen *screen = QApplication::screens().at(0);
    int screenWidth = screen->availableSize().width();
    int screenHeight = screen->availableSize().height();

    qDebug() << "Window:\n";
    qDebug() << "X = " << screenWidth;
    qDebug() << "Y = " << screenHeight;

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    Widget w;
    w.setGeometry(0,0, screenWidth/8, screenHeight/8);
    w.show();

    return a.exec();
}
