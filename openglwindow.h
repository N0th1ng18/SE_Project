#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:


};

#endif // OPENGLWINDOW_H
