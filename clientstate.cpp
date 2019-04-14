#include "clientstate.h"

ClientState::ClientState()
{
    numOfObjects = 0;
}

ClientState::~ClientState()
{
    for(size_t i=0; i < objects.size(); i++){
        delete &objects.at(i);
    }
    vector<Object>().swap(objects);
}

void ClientState::update()
{
    for(size_t i=0; i < objects.size(); i++){
        objects.at(i).update();
    }
}

void ClientState::render()
{
    for(size_t i=0; i < objects.size(); i++){
        objects.at(i).render();
    }
}

/***************Objects***************/
void ClientState::addObject(Materials *materials, unsigned int shaderID, unsigned int vaoID, unsigned int textureID)
{
    Object *newObject = new Object(materials, shaderID, vaoID, textureID);
    objects.push_back(*newObject);
    numOfObjects++;
}

