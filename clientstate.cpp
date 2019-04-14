#include "clientstate.h"

ClientState::ClientState()
{
    numOfObjects = 0;
}

ClientState::~ClientState()
{
    for(size_t i=0; i < objects.size(); i++){
        delete (objects.at(0));
    }
    vector<Object*>().swap(objects);
}

void ClientState::update()
{
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).update();
    }
}

void ClientState::render(QOpenGLFunctions *gl)
{
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).render(gl);
    }
}

/***************Objects***************/
void ClientState::addObject(Object *obj)
{
    objects.push_back(obj);
    numOfObjects++;
}

