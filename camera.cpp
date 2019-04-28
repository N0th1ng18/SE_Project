#include "camera.h"

Camera::Camera(Materials *materials, unsigned int shaderID, QVector3D *pos)
{
    this->materials = materials;
    this->shaderID = shaderID;
    this->pos = pos;
}
Camera::~Camera()
{

}
void Camera::update()
{

}
void Camera::render(QOpenGLFunctions *gl, QMatrix4x4* projectionMatrix)
{
    materials->getShader(shaderID)->bind();

    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, -2.0f);

    materials->getShader(shaderID)->getShader()->setUniformValue("projectionMatrix", *projectionMatrix);
    materials->getShader(shaderID)->getShader()->setUniformValue("viewMatrix", viewMatrix);

    materials->getShader(shaderID)->unbind();
}
