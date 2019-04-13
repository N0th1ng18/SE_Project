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
#include <vector>

#include "materials.h"
#include "texture.h"
#include "shader.h"
#include "model.h"
#include "vao.h"
#include "vbo.h"


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

    void loadMaterials();

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

    Materials *materials = new Materials();
    //Needs to be classes
        //Holds all the OpenGL structures needed for the Renderer
        //struct Materials {
            //Models
            //Shaders
            //Textures
            //VAOs
            //VBOs
        //};

        //Holds the ServerState that is sent to the renderer
        //struct ClientState {
            //Cameras
            //Players
            //Objects
            //Maps
            //Texts
            //Sounds
       // };

        //Holds the Actions the User has taken to be sent to the Server's Game Thread
        //Action State Resets before every update.
        //struct ActionState {
            //bool used_PowerUp1
            //bool used_PowerUp2
            //bool rolled
        //};

};

#endif // OPENGLWINDOW_H
