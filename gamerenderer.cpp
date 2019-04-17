#include "gamerenderer.h"

GameRenderer::GameRenderer(QObject *parent) : QObject(parent)
{

}

GameRenderer::GameRenderer(QObject* parent, OpenGLWindow *glWindow):
        QObject(parent), m_gameView(glWindow)
{

}


void GameRenderer::setRenderView(OpenGLWindow * newGameView){
    m_gameView = newGameView;
}

void GameRenderer::launchGame(){
    m_gameView->show();
}

void GameRenderer::exitGame(){
    m_gameView->close();
    emit beginExit();
}
