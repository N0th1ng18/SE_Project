#ifndef CAMERA_H
#define CAMERA_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

#include "materials.h"

/*
 * Description: The Camera class constructs and passes the projection
 *              and view matrix to a defined shader.
 *
 * Author: Nick
 *
 */

class Camera
{
public:
    Camera(Materials *materials, unsigned int shaderID, QVector3D *pos);
    ~Camera();
    void update();
    void render(QOpenGLFunctions* gl, QMatrix4x4* projectionMatrix);
private:
    Materials* materials = nullptr;
    unsigned int shaderID;

    QMatrix4x4 viewMatrix;

    QVector3D* pos = nullptr;
    QVector3D* vel = nullptr;
    QVector3D* acc = nullptr;
};

#endif // CAMERA_H
