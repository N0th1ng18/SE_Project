#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H

#include "object.h"
#include "camera.h"
#include "vector"

using namespace std;

class ClientState
{
public:
    ClientState();
    ~ClientState();

    void update();
    void render(QOpenGLFunctions* gl);

    QMatrix4x4* getProjection();

    void addCamera(Camera *cam);
    void removeCamera(int index);
    void setActiveCamera(int activeCamID);

    void addObject(Object *obj);
    void removeObject(int index);



protected:

private:
    QMatrix4x4 projectionMatrix;

    int activeCameraID = 0;
    vector<Camera*> cameras;
    vector<Object*> objects;


};

#endif // CLIENTSTATE_H
