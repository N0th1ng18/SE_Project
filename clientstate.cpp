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
    //Cameras
    for(size_t i=0; i < cameras.size(); i++){
        (*cameras.at(i)).update();
    }

    //Objects
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).update();
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

