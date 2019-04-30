#include "button.h"

Button::Button(Materials *materials
               , unsigned int shaderID
               , unsigned int vaoID
               , unsigned int textureID1
               , unsigned int textureID2
               , QVector3D *pos)
{
    this->materials = materials;
    this->shaderID = shaderID;
    this->vaoID = vaoID;
    this->textureID1 = textureID1;
    this->textureID2 = textureID2;
    this->pos = pos;
    this->oScale = new QVector3D(1.0f, 1.0f, 1.0f);
    this->clicked = false;
}

Button::~Button()
{
    delete pos;
    delete oScale;
}

void Button::update(Input* input, float width, float height)
{
    if(input->getPressed() && input->getPos()->y() > this->yoff * height)
    {
        this->clicked = true;
    }else{
        this->clicked = false;
    }
}
void Button::render(QOpenGLFunctions *gl)
{
    //Bind Shader
    materials->getShader(shaderID)->bind();
    //Bind VAO
    materials->getVAO(vaoID)->bind();
    //Bind Textures
    if(!clicked){
        materials->getTexture(textureID1)->bind();
    }else{
        materials->getTexture(textureID2)->bind();
    }
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
    if(!clicked){
        materials->getTexture(textureID1)->unbind();
    }else{
        materials->getTexture(textureID2)->unbind();
    }
    materials->getShader(shaderID)->unbind();
    /*******************************************************************/

}
void Button::setScale(QVector3D* s)
{
    oScale->setX(s->x());
    oScale->setY(s->y());
    oScale->setZ(s->z());
}

QVector3D* Button::getPos()
{
    return this->pos;
}
void Button::setPos(QVector3D* p)
{
    this->pos = p;
}

void Button::setBounds(float xoff, float yoff)
{
    this->xoff = xoff;
    this->yoff = yoff;
}
