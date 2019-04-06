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

    //OpenGL Settings
    glClearColor(1, 0, 0, 1);
    glEnable(GL_CULL_FACE);

    initShaders();

}

void OpenGLWindow::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex.vsh"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/frag.fsh"))
        close();

    // Link shader pipeline
    if (!program.link())
    {
        qDebug() << "Failed to link shader program";
        close();
    }

    // Bind shader pipeline for use
    if (!program.bind())
    {
        qDebug() << "Failed to bind shader program";
        close();
    }
}

void OpenGLWindow::paintGL()
{

}

void OpenGLWindow::resizeGL(int w, int h)
{

}
