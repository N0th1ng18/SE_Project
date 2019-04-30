#ifndef OBJECT_H
#define OBJECT_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

#include "materials.h"

class Object
{
public:
    Object(Materials *materials
           , unsigned int shaderID
           , unsigned int vaoID
           , unsigned int textureID
           , QVector3D *newPos);
    ~Object();
    void update();
    void render(QOpenGLFunctions *gl);
    void setScale(QVector3D* s);
    QVector3D* getNewPos();
    void setNewPos(QVector3D* np);
    QVector3D* getPos();
    void setPos(QVector3D* p);
protected:

private:
    Materials *materials = nullptr;
    unsigned int shaderID;
    unsigned int vaoID;
    unsigned int textureID;

    QMatrix4x4 transformationMatrix;

    QVector3D *newPos = nullptr;
    QVector3D *pos = nullptr;
    QVector3D *vel = nullptr;
    QVector3D *acc = nullptr;

    QVector3D *oScale = nullptr;
};

#endif // OBJECT_H
