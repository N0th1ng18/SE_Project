#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLFunctions>

using namespace std;

/*
 * Description: Model loads a 2D quad (2 triangles) to load our textures
 *              for our 2d game.
 *
 * Author: Nick
 *
 */

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
