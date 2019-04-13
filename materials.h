#ifndef MATERIALS_H
#define MATERIALS_H

#include "model.h"
#include "shader.h"
#include "texture.h"

class Materials
{
public:
    Materials();
    ~Materials();
    int addModel(Model* model);
    void removeModel(int index);
    int addShader(Shader* shader);
    void removeShader(int index);
    int addTexture(Texture* texture);
    void removeTexture(int index);

protected:

private:
    vector<Model> models;
    int numOfModels;
    vector<Shader> shaders;       //number of shaders
    int numOfShaders;
    vector<Texture> textures;     //number of textures
    int numOfTextures;
};

#endif // MATERIALS_H
