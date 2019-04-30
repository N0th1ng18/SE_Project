#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H

#include <QOpenGLShaderProgram>
#include "object.h"
#include "camera.h"
#include "vector"
#include "font.h"
#include "player.h"
#include "button.h"

using namespace std;

class ClientState
{
public:
    ClientState();
    ~ClientState();

    void update();
    void render(QOpenGLFunctions* gl);

    QMatrix4x4* getProjection();
    QMatrix4x4* getOrthographic();

    void addCamera(Camera* cam);
    void removeCamera(int index);
    void setActiveCamera(int activeCamID);

    void addObject(Object* obj);
    void removeObject(int index);

    void addButton(Button* button);
    void removeButton(int index);

    void addText(Font* font);
    void removeText(int index);

    void setAspectRatio(float aspectRatio);
    void setWidth(float width);
    void setHeight(float height);
    float getAspectRatio();

    int getState();
    void setState(int state);
    int getNumPlayers();
    void setNumPlayers(int numPlayers);
    void addPlayer(Player* player);
    void removeALLPlayer();
    int getHasTurn();
    void setHasTurn(int hasTurn);
    int getMapID();
    void setMapID(int mapID);

    void clear();

protected:

private:
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 orthographicMatrix;

    int activeCameraID = 0;
    vector<Camera*> cameras;
    vector<Object*> objects;
    vector<Button*> buttons;
    vector<Font*> texts;

    int state;
    int hasTurn;
    int mapID;
    int numPlayers;
    vector<Player*> players;

    float aspectRatio = 0.0f;
    float width = 100.0f;
    float height = 100.0f;

    enum State{
        lobby = 3,
        game,
        miniGame
    };


};

#endif // CLIENTSTATE_H
