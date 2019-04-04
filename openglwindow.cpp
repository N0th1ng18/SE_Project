#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWidget *parent) :
    QOpenGLWidget(parent)
{
    qDebug("OpenGLWindow Constructor");
}

OpenGLWindow::~OpenGLWindow()
{
    makeCurrent();
    /*Clean Up*/

    /*--------*/
    doneCurrent();
}


void OpenGLWindow::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(1, 0, 0, 1);

}

void OpenGLWindow::paintGL()
{

}

void OpenGLWindow::resizeGL(int w, int h)
{

}
