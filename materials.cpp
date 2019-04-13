#include "materials.h"

using namespace std;

Materials::Materials()
{
    this->numOfModels = 0;
    this->numOfShaders = 0;
    this->numOfTextures = 0;
}

Materials::~Materials(){
    //Correctly deallocate Vectors
    vector<Model> models;
    vector<Shader> shaders;
    vector<Texture> textures;
    vector<Model>().swap(models);
    vector<Shader>().swap(shaders);
    vector<Texture>().swap(textures);
}

int Materials::addModel(Model* model)
{
    models.push_back(*model);
    numOfModels++;
    return numOfModels-1;
}

void Materials::removeModel(int index)
{
    models.erase(models.begin() + index);
    numOfModels--;
}

int Materials::addShader(Shader* shader)
{
    shaders.push_back(*shader);
    numOfShaders++;
    return numOfShaders-1;
}

void Materials::removeShader(int index)
{
    shaders.erase(shaders.begin() + index);
    numOfShaders--;
}

int Materials::addTexture(Texture* texture)

{
    textures.push_back(*texture);
    numOfTextures++;
    return numOfTextures-1;
}

void Materials::removeTexture(int index)
{
    textures.erase(textures.begin() + index);
    numOfTextures--;
}
