#include "clientstate.h"

ClientState::ClientState()
{

}

ClientState::~ClientState()
{
    for(size_t i=0; i < objects.size(); i++){
        delete (objects.at(0));
    }
    vector<Object*>().swap(objects);

    //Delete Text
}

void ClientState::update()
{
    //State specific tasks
    switch(getState())
    {
    case lobby:
    {
        for(size_t i=0; i < static_cast<size_t>(numPlayers); i++)
        {
            //set pos to newPos
            this->players.at(i)->getObj()->getPos()->setX(this->players.at(i)->getObj()->getNewPos()->x());
            this->players.at(i)->getObj()->getPos()->setY(this->players.at(i)->getObj()->getNewPos()->y());
            this->players.at(i)->getObj()->getPos()->setZ(this->players.at(i)->getObj()->getNewPos()->z());
        }
        break;
    }
    case game:
    {
        //Interpolating position
        break;
    }
    case miniGame:
    {

        break;
    }
    }


    //Cameras
    for(size_t i=0; i < cameras.size(); i++){
        (*cameras.at(i)).update();
    }

    //Objects
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).update();
    }

    //Players
    for(size_t i=0; i < players.size(); i++){
        (*players.at(i)).update();
    }

    //Buttons
    for(size_t i=0; i < buttons.size(); i++){
        (*buttons.at(i)).update();
    }

    //Texts
    for(size_t i=0; i < texts.size(); i++){
        (*texts.at(i)).update();
    }
}

void ClientState::render(QOpenGLFunctions* gl)
{
    //Cameras
    for(size_t i=0; i < cameras.size(); i++){
        (*cameras.at(i)).render(gl, &projectionMatrix);
    }

    //Objects
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).render(gl);
    }

    //Players
    for(size_t i=0; i < players.size(); i++){
        (*players.at(i)).render(gl);
    }

    //Buttons
    for(size_t i=0; i < buttons.size(); i++){
        (*buttons.at(i)).render(gl);
    }

    //Text
    for(size_t i=0; i < texts.size(); i++){
        (*texts.at(i)).render(gl, this->getOrthographic(), width, height, getAspectRatio());
    }
}

/***************Objects***************/
void ClientState::addCamera(Camera* cam)
{
    cameras.push_back(cam);
}

void ClientState::setActiveCamera(int activeCamID)
{
    this->activeCameraID = activeCamID;
}

void ClientState::addObject(Object* obj)
{
    objects.push_back(obj);
}

void ClientState::addText(Font* font)
{
    texts.push_back(font);
}

void ClientState::addButton(Button* button)
{
    buttons.push_back(button);
}

/************Projection**************/
QMatrix4x4* ClientState::getProjection()
{
    return &projectionMatrix;
}

/************Orthographic**************/
QMatrix4x4* ClientState::getOrthographic()
{
    return &orthographicMatrix;
}

/************AspectRatio**************/
void ClientState::setAspectRatio(float aspectRatio)
{
    this->aspectRatio = aspectRatio;
}

float ClientState::getAspectRatio()
{
    return this->aspectRatio;
}

void ClientState::setWidth(float width)
{
    this->width = width;
}

void ClientState::setHeight(float height)
{
    this->height = height;
}

/*************ServerState*************/
int ClientState::getState()
{
    return this->state;
}
void ClientState::setState(int state)
{
    this->state = state;
}

void ClientState::addPlayer(Player* player)
{
    this->players.push_back(player);
}

void ClientState::removeALLPlayer()
{
    for(size_t i=0; i < this->players.size(); i++)
    {
        delete players.at(i);
    }
}


int ClientState::getNumPlayers()
{
    return this->numPlayers;
}
void ClientState::setNumPlayers(int numPlayers)
{
    this->numPlayers = numPlayers;
}
int ClientState::getHasTurn()
{
    return hasTurn;
}
void ClientState::setHasTurn(int hasTurn)
{
    this->hasTurn = hasTurn;
}
int ClientState::getMapID()
{
    return mapID;
}
void ClientState::setMapID(int mapID)
{
    this->mapID = mapID;
}

void ClientState::clear()
{
    //Only need to clear players
    removeALLPlayer();

}
