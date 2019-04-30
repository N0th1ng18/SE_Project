#ifndef INPUT_H
#define INPUT_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

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
