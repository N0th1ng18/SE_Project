#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLFunctions>

using namespace std;

class Model
{
public:
    Model();
    Model(const QString filePath);
    ~Model();
    vector<GLfloat> getVertices();
    vector<GLfloat> getTexCoords();
    int getNumVertices();

protected:

private:
    vector<GLfloat> vertices;
    vector<GLfloat> texCoords;
    int numOfVertices;
};

#endif // MODEL_H
