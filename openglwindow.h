#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();

private:
    QOpenGLShaderProgram program;

};

#endif // OPENGLWINDOW_H
