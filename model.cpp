#include "model.h"

Model::Model()
{
    /*Default Square Model*/
    numOfVertices = 0;
    //Vertices
    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(0.5f);
    vertices.push_back(0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(0.5f);
    vertices.push_back(0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(-0.5f);
    vertices.push_back(0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(0.0f);
    numOfVertices = 6;

    //Texture Coords
    texCoords.push_back(0.0f);
    texCoords.push_back(0.0f);

    texCoords.push_back(1.0f);
    texCoords.push_back(0.0f);

    texCoords.push_back(1.0f);
    texCoords.push_back(1.0f);

    texCoords.push_back(1.0f);
    texCoords.push_back(1.0f);

    texCoords.push_back(0.0f);
    texCoords.push_back(1.0f);

    texCoords.push_back(0.0f);
    texCoords.push_back(0.0f);
}

Model::Model(const QString filePath)
{
    //Load vertcies and texture coordinates from path
}

Model::~Model()
{
    //Correctly de-allocate vectors
    vector<GLfloat>().swap(vertices);
    vector<GLfloat>().swap(texCoords);
}

vector<GLfloat> Model::getVertices()
{
    return vertices;
}

vector<GLfloat> Model::getTexCoords()
{
    return texCoords;
}

int Model::getNumVertices(){
    return numOfVertices;
}

