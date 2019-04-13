#include "model.h"

Model::Model()
{
    //Default Square model

}
Model::Model(std::string)
{
    //Load vertcies and texture coordinates from path
}

Model::~Model()
{

}

GLfloat* Model::getVerticies()
{
    return verticies;
}
GLfloat* Model::getTexCoords()
{
    return texCoords;
}

void Model::setVerticies(GLfloat* verticies)
{
    this->verticies = verticies;
}
void Model::setTexCoords(GLfloat* texCoords)
{
    this->texCoords = texCoords;
}

