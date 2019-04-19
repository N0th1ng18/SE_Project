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
           , QVector3D *pos);
    ~Object();
    void update();
    void render(QOpenGLFunctions *gl);
protected:

private:
    Materials *materials = nullptr;
    unsigned int shaderID;
    unsigned int vaoID;
    unsigned int textureID;

    QMatrix4x4 transformationMatrix;

    QVector3D *pos = nullptr;
    QVector3D *vel = nullptr;
    QVector3D *acc = nullptr;
};

#endif // OBJECT_H
