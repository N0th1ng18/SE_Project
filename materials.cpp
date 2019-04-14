#include "materials.h"

using namespace std;

Materials::Materials()
{
    this->numOfVAOs = 0;
    this->numOfShaders = 0;
    this->numOfTextures = 0;
}

Materials::~Materials(){
    //Correctly deallocate Vectors
    for(size_t i=0; i < shaders.size(); i++){
        delete (shaders.at(0));
    }
    vector<Shader*>().swap(shaders);

    for(size_t i=0; i < textures.size(); i++){
        delete (textures.at(0));
    }
    vector<Texture*>().swap(textures);

    for(size_t i=0; i < vaos.size(); i++){
        delete (vaos.at(0));
    }
    vector<VAO*>().swap(vaos);
}

unsigned int Materials::addVAO(VAO *vao)
{
    vaos.push_back(vao);
    numOfVAOs++;
    return numOfVAOs-1;
}
void Materials::removeVAO(int index)
{
    vaos.erase(vaos.begin() + index);
    numOfVAOs--;
}

VAO* Materials::getVAO(unsigned int index)
{
    return vaos.at(index);
}

unsigned int Materials::addShader(Shader *shader)
{
    shaders.push_back(shader);
    numOfShaders++;
    return numOfShaders-1;
}

void Materials::removeShader(int index)
{
    shaders.erase(shaders.begin() + index);
    numOfShaders--;
}

Shader* Materials::getShader(unsigned int index)
{
    return shaders.at(index);
}

unsigned int Materials::addTexture(Texture *texture)

{
    textures.push_back(texture);
    numOfTextures++;
    return numOfTextures-1;
}

void Materials::removeTexture(int index)
{
    textures.erase(textures.begin() + index);
    numOfTextures--;
}

Texture* Materials::getTexture(unsigned int index)
{
    return textures.at(index);
}

