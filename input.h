#ifndef INPUT_H
#define INPUT_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

/*
 * Description: Input pulls the "mouse" / touches on the phone
 *              and stores the values to be used for any class.
 *
 * Author: Nick
 *
 */

class Input
{
public:
    Input();
    ~Input();

    void setPressed(bool p);
    bool getPressed();
    void setPos(QVector3D* pos);
    QVector3D* getPos();

private:
    bool pressed;
    QVector3D* pos = nullptr;
};

#endif // INPUT_H
