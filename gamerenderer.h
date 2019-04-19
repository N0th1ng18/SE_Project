#ifndef GAMERENDERER_H
#define GAMERENDERER_H

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
