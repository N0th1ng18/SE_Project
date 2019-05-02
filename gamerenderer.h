#ifndef GAMERENDERER_H
#define GAMERENDERER_H


/*
 *
 *  Description
 *
 *  Renders the OpenGLWindow.
 *
 *  Class became somewhat obsolete as
 *  the game is now rendered through other means
 *
 *
 */

#include <QObject>
#include "openglwindow.h"

class GameRenderer : public QObject
{
    Q_OBJECT
public:
    explicit GameRenderer(QObject *parent = nullptr);
    explicit GameRenderer(OpenGLWindow *glWindow = nullptr);

    void setRenderView(OpenGLWindow * newGameView);
signals:
    void beginExit();

public slots:
    void launchGame();
    void exitGame();

private:
    OpenGLWindow * m_gameView = nullptr;

};

#endif // GAMERENDERER_H
