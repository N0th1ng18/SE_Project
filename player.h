#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QOpenGLShaderProgram>
#include "object.h"
//#include "powerup.h"

using namespace std;

class Player
{
public:
    Player(Materials *materials
           , unsigned int shaderID
           , unsigned int vaoID
           , int ID
           , unsigned int textureID
           , int hasMoved
           , QVector3D *pos);
    ~Player();

    /*Object*/
    Object* getObj();

    /*Add Remove PowerUps*/
    //void addPowerUp(PowerUp* p);
    //void removePowerUp(int powerUpID);

    /*Getters & Setters*/
    int getID();
    void setID(int id);
    int getImgID();
    void setImgID(int imgID);
    QString getAddress();
    void setAddress(QString address);
    int getPort();
    void setPort(int port);
    int getHasMoved();
    void setHasMoved(int hasMoved);

    void update();
    void render(QOpenGLFunctions *gl);

private:
    int ID;
    int imgID;
    QString address;
    int port;
    int hasMoved;
    Object* object;
    //vector<PowerUp*> powerUps;





};

#endif // PLAYER_H
