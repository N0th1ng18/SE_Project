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
#include "clientstate.h"


class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{

public:
    OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow() override;

protected:
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void loadMaterials();
    void loadEntities();

private:
    QOpenGLFunctions *gl;
    int g_width, g_height;
    float g_aspectRatio;

    QBasicTimer timer;

    ClientState *clientState = new ClientState();
    Materials *materials = new Materials();

    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;

    //Needs to be classes
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
