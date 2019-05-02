#ifndef BUTTON_H
#define BUTTON_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

#include "materials.h"
#include "input.h"


/*
 * Description: A button is an object with a set boundry used for input.
 *              It supports two textures to be switched between depending
 *              on the mouse(touch screen).
 *
 * Author: Nick
 *
 */

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
    void update(Input* input, float width, float height);
    void render(QOpenGLFunctions *gl);
    void setScale(QVector3D* s);
    QVector3D* getPos();
    void setPos(QVector3D* p);
    void setBounds(float xoff, float yoff);

private:
    Materials *materials = nullptr;
    unsigned int shaderID;
    unsigned int vaoID;
    unsigned int textureID1;
    unsigned int textureID2;

    QMatrix4x4 transformationMatrix;

    QVector3D *pos = nullptr;
    QVector3D *oScale = nullptr;

    //Bounds
    float xoff = 0.0f;
    float yoff = 0.0f;


    bool clicked;
};

#endif // BUTTON_H
