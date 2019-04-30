#ifndef BUTTON_H
#define BUTTON_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

#include "materials.h"

class Button
{
public:
    Button(Materials *materials
           , unsigned int shaderID
           , unsigned int vaoID
           , unsigned int textureID1
           , unsigned int textureID2
           , QVector3D *pos);
    ~Button();
    void update();
    void render(QOpenGLFunctions *gl);
    void setScale(QVector3D* s);
    QVector3D* getPos();
    void setPos(QVector3D* p);

private:
    Materials *materials = nullptr;
    unsigned int shaderID;
    unsigned int vaoID;
    unsigned int textureID1;
    unsigned int textureID2;

    QMatrix4x4 transformationMatrix;

    QVector3D *pos = nullptr;
    QVector3D *oScale = nullptr;

    bool clicked;
};

#endif // BUTTON_H
