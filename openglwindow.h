#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void loadObjects();
    void initShaders();

private:
    QOpenGLShaderProgram program;

    QOpenGLVertexArrayObject vao;   //Buffer to store all VBOs
    QOpenGLBuffer vertex_VBO;       //Buffer for verticies

    QMatrix4x4 orthoMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 transformationMatrix;



};

#endif // OPENGLWINDOW_H
