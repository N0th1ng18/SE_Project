#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QObject>
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
#include <QSysInfo>
#include <QMouseEvent>

#include "materials.h"
#include "texture.h"
#include "shader.h"
#include "model.h"
#include "vao.h"
#include "vbo.h"
#include "clientstate.h"
#include "sound.h"
#include "font.h"
#include "clientgameprotocol.h"
#include "input.h"


/*
 * Description: The OpenGLWindow provides the functionality to use opengl ES
 *              on android. QT manages the game loop and calls overrided
 *              opengl functions (initializeGL, resizeGL, paintGL) Timer Event
 *              is used to update every 12 ms -> 60 updates a second.This allows
 *              for movement support for anything in clientState.
 *
 * Author: Nick
 *
 */

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{


public:
    OpenGLWindow(QString userName, QString address, quint16 port, QWidget *parent = nullptr);
    ~OpenGLWindow() override;

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void connectToServer();
    void loadMaterials();
    void loadEntities();

 signals:
    void gameLaunched();



private:
    enum Textures{

    };
    enum Shaders{

    };

    ClientGameProtocol* socketP = nullptr;
    QString userName;
    QString address;
    quint16 port;

    QOpenGLFunctions *gl = nullptr;
    int g_width, g_height;
    float g_aspectRatio;

    QBasicTimer timer;

    Input* input = new Input();
    ClientState *clientState = new ClientState(input);
    Materials *materials = new Materials();


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
