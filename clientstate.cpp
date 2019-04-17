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
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).update();
    }

    for(size_t i=0; i < texts.size(); i++){
        (*texts.at(i)).update();
    }
}

void ClientState::render(QOpenGLFunctions* gl, QPainter* painter)
{
    for(size_t i=0; i < objects.size(); i++){
        (*objects.at(i)).render(gl);
    }

    for(size_t i=0; i < texts.size(); i++){
        (*texts.at(i)).render(painter);
    }
}

/***************Objects***************/
void ClientState::addObject(Object *obj)
{
    objects.push_back(obj);
}

void ClientState::addText(Text *txt)
{
    texts.push_back(txt);
}
