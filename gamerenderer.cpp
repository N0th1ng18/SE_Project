#include "gamerenderer.h"

GameRenderer::GameRenderer(QObject *parent) : QObject(parent)
{

}

GameRenderer::GameRenderer(OpenGLWindow *glWindow): m_gameView(glWindow)
{

}

// Creates a new  instance of the game
void GameRenderer::setRenderView(OpenGLWindow * newGameView){
    m_gameView = newGameView;
}

// Renders the game on the users device
void GameRenderer::launchGame(){
    m_gameView->show();
}

void GameRenderer::exitGame(){
    m_gameView->close();
    emit beginExit();
}
