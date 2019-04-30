#include "input.h"

Input::Input()
{
    pos = new QVector3D(0.0f, 0.0f, 0.0f);
}

Input::~Input()
{
    delete pos;
}

void Input::setPressed(bool p)
{
    this->pressed = p;
}
bool Input::getPressed()
{
    return this->pressed;
}
void Input::setPos(QVector3D* pos)
{
    this->pos = pos;
}
QVector3D* Input::getPos()
{
    return pos;
}
