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
    //Camera update

    for(size_t i=0; i < cameras.size(); i++){
        (*cameras.at(i)).update();
    }


    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).update();
    }

}

void ClientState::render(QOpenGLFunctions* gl)
{
    for(size_t i=0; i < cameras.size(); i++){
        (*cameras.at(i)).render(gl, &projectionMatrix);
    }

    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).render(gl);
    }
}

/***************Objects***************/
void ClientState::addCamera(Camera *cam)
{
    cameras.push_back(cam);
}

void ClientState::setActiveCamera(int activeCamID)
{
    this->activeCameraID = activeCamID;
}

void ClientState::addObject(Object *obj)
{
    objects.push_back(obj);
}

/************Projection**************/
QMatrix4x4* ClientState::getProjection()
{
    return &projectionMatrix;
}

