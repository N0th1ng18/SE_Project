#include "player.h"

Player::Player(Materials *materials
               , unsigned int shaderID
               , unsigned int vaoID
               , int ID
               , unsigned int textureID
               , int hasMoved
               , QVector3D *newPos)
{
    this->ID = ID;
    this->hasMoved = hasMoved;

    object = new Object(materials, shaderID, vaoID, textureID, newPos);
}

Player::~Player()
{
    delete object;
}


void Player::update()
{
    object->update();
}
void Player::render(QOpenGLFunctions *gl)
{
    object->render(gl);
}

Object* Player::getObj()
{
    return this->object;
}

/*Add Remove PowerUps*/
//void Player::addPowerUp(PowerUp* p)
//{
//    powerUps.push_back(p);
//}
//void Player::removePowerUp(int powerUpID)
//{
//
//}

/*Getters & Setters*/
int Player::getID()
{
    return this->ID;
}
void Player::setID(int id)
{
    this->ID = id;
}

int Player::getImgID()
{
    return this->imgID;
}

void Player::setImgID(int imgID)
{
    this->imgID = imgID;
}

QString Player::getAddress()
{
    return this->address;
}
void Player::setAddress(QString address)
{
    this->address = address;
}
int Player::getPort()
{
    return this->port;
}
void Player::setPort(int port)
{
    this->port = port;
}

int Player::getHasMoved()
{
    return this->hasMoved;
}
void Player::setHasMoved(int hasMoved)
{
    this->hasMoved = hasMoved;
}
