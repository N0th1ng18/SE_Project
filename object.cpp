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

}

Object::~Object()
{
    delete acc;
    delete vel;
    delete pos;
}

void Object::update()
{

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
