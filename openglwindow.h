#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QBasicTimer>
#include <QOpenGLTexture>
#include <QPainter>
#include <QFontMetrics>

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
    void initTextures();

private:
    int g_width, g_height;
    float g_aspectRatio;

    QBasicTimer timer;

    QOpenGLShaderProgram program;

    QOpenGLVertexArrayObject vao;   //Buffer to store all VBOs
    QOpenGLBuffer vertex_VBO;       //Buffer for verticies
    QOpenGLBuffer texCoords_VBO;    //Buffer for Texture Coordinates

    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 transformationMatrix;

    QOpenGLTexture *textures[5];

};

#endif // OPENGLWINDOW_H
