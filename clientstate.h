#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H

#include "object.h"
#include "vector"

using namespace std;

class ClientState
{
public:
    ClientState();
    ~ClientState();

    void update();
    void render(QOpenGLFunctions *gl);

    void addObject(Object *obj);

protected:

private:
    int numOfObjects;
    vector<Object*> objects;

};

#endif // CLIENTSTATE_H
