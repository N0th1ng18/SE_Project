#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLFunctions>
#include <string>

class Model
{
public:
    Model();
    Model(std::string path);
    ~Model();
    GLfloat* getVerticies();
    GLfloat* getTexCoords();
    void setVerticies(GLfloat* verticies);
    void setTexCoords(GLfloat* texCoords);

protected:

private:
    GLfloat *verticies;
    GLfloat *texCoords;

};

#endif // MODEL_H
