#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QBasicTimer>



class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{


public:
    OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow();

protected:
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void loadObjects();
    void initShaders();

 signals:
    void gameLaunched();



private:
    QBasicTimer timer;

    QOpenGLShaderProgram program;

    QOpenGLVertexArrayObject vao;   //Buffer to store all VBOs
    QOpenGLBuffer vertex_VBO;       //Buffer for verticies

    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 transformationMatrix;



};

#endif // OPENGLWINDOW_H
