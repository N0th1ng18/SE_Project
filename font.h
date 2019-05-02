#ifndef TEXT_H
#define TEXT_H

#include <qstring.h>
#include <qfile.h>
#include <QtDebug>
#include <QVector2D>
#include <QOpenGLFunctions>
#include "vao.h"
#include "vbo.h"
#include "materials.h"

using namespace std;

/*
 * Description: Font Renders Text.  Each character is broken up
 *              into two triangles and rendered into the correct
 *              position that is read in from the text file.
 *
 * Author: Nick
 *
 */

class Font
{
public:
    Font(QString fontPath
         , Materials* materials
         , unsigned int textureID
         , unsigned int shaderID
         , float fontSize);
    ~Font();
    void update();
    void render(QOpenGLFunctions *gl, QMatrix4x4* orthographicMatrix, float width, float height, float aspectRatio);
    void addString(QString str, float xPos, float yPos);

private:
    void loadFont(QString filePath);
    struct fChar{
        unsigned short id;
        float x_tex;
        float y_tex;
        float char_width_tex;
        float char_height_tex;
        float char_width_vert;
        float char_height_vert;
        float xoffset_vert;
        float yoffset_vert;
        float xadvance_vert;
    };

    struct StringSet{
        unsigned int vaoID;
        int numVertices;
        float xPos;
        float yPos;
        float width;
        float height;
    };

    Materials* materials = nullptr;
    unsigned int textureID;
    unsigned int shaderID;

    QMatrix4x4 transformationMatrix;

    //Global Character and Image Settings
    float padX;
    float padY;
    float lineHeight;
    float imgWidth;
    float imgHeight;
    //Used to hold all characters info
    fChar* chars;
    //Keeps track of the number of characters in Font
    int charCount = 0;
    //Keeps track of all set of Strings in this Font type
    vector<StringSet*> strSets;
    //Font Size
    float fontScale;

    QVector3D *scale;
    //Control Point
    QVector3D *cPoint;
};

#endif // TEXT_H
