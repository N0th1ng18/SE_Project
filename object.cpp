#include "object.h"
#include <QOpenGLFunctions>

Object::Object(Materials *materials
               , unsigned int shaderID
               , unsigned int vaoID
               , unsigned int textureID
               , QVector3D *pos)
{
    this->materials = materials;
    this->shaderID = shaderID;
    this->vaoID = vaoID;
    this->textureID = textureID;
    this->pos = pos;
    this->vel = new QVector3D(0.0f, 0.0f, 0.0f);
    this->oScale = new QVector3D(1.0f, 1.0f, 1.0f);
}

Object::~Object()
{
    delete acc;
    delete vel;
    delete pos;
}

void Object::update()
{
    pos->setX(pos->x() + vel->x());
    pos->setY(pos->y() + vel->y());
    pos->setZ(pos->z() + vel->z());
}

void Object::render(QOpenGLFunctions *gl)
{

    //Bind Shader
    materials->getShader(shaderID)->bind();
    //Bind VAO
    materials->getVAO(vaoID)->bind();
    //Bind Textures
    materials->getTexture(textureID)->bind();
    //Interpolate

    //Transformation
    transformationMatrix.setToIdentity();
    transformationMatrix.scale(oScale->x(), oScale->y(), oScale->z());
    transformationMatrix.translate(pos->x(), pos->y(), pos->z());

    //Uniforms
    materials->getShader(shaderID)->getShader()->setUniformValue("transformationMatrix", transformationMatrix);
    materials->getShader(shaderID)->getShader()->setUniformValue("texture", 0);

    //Draw
    gl->glDrawArrays(GL_TRIANGLES, 0, materials->getVAO(vaoID)->getNumVertices()); //num of verticies
    //Unbind
    materials->getVAO(vaoID)->unbind();
    materials->getTexture(textureID)->unbind();
    materials->getShader(shaderID)->unbind();
    /*******************************************************************/

}

void Object::setScale(QVector3D* s)
{
    oScale->setX(s->x());
    oScale->setY(s->y());
    oScale->setZ(s->z());
}
