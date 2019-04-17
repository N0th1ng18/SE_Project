#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H

#include "object.h"
#include "vector"
#include "text.h"

using namespace std;

class ClientState
{
public:
    ClientState();
    ~ClientState();

    void update();
    void render(QOpenGLFunctions* gl, QPainter* painter);

    void addObject(Object *obj);
    void addText(Text *txt);

protected:

private:
    vector<Object*> objects;
    vector<Text*> texts;

};

#endif // CLIENTSTATE_H
