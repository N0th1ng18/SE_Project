#include "font.h"

Font::Font(QString fontPath
           , Materials* materials
           , unsigned int textureID
           , unsigned int shaderID
           , float fontScale)
{
    this->materials = materials;
    this->textureID = textureID;
    this->shaderID = shaderID;
    this->fontScale = fontScale;
    loadFont(fontPath);

    scale = new QVector3D(1.0f, 1.0f, 1.0f);
    cPoint = new QVector3D(0.0f, 0.0f, 0.0f);
}

Font::~Font()
{

}

void Font::update()
{

}
void Font::render(QOpenGLFunctions *gl, QMatrix4x4* orthographicMatrix, float width, float height, float aspectRatio)
{
    for(size_t i=0; i < strSets.size(); i++)
    {
        //Bind Shader
        materials->getShader(shaderID)->bind();
        //Bind VAO
        materials->getVAO(strSets.at(i)->vaoID)->bind();
        //Bind Textures
        materials->getTexture(textureID)->bind();
        //Interpolate

        //Transformation
        transformationMatrix.setToIdentity();

        transformationMatrix.scale(scale->x() * (1.0f/aspectRatio), scale->y(), scale->z());

        //Centered
        cPoint->setX(strSets.at(i)->width / 2.0f);
        cPoint->setY(strSets.at(i)->height / 2.0f);
        //Left Top
        //cPoint->setX(0.0f);
        //cPoint->setY(0.0f);

        transformationMatrix.translate((strSets.at(i)->xPos - cPoint->x()), (strSets.at(i)->yPos - cPoint->y()), 0.0f);

        //Uniforms

        materials->getShader(shaderID)->getShader()->setUniformValue("orthographicMatrix", *orthographicMatrix);
        materials->getShader(shaderID)->getShader()->setUniformValue("transformationMatrix", transformationMatrix);
        materials->getShader(shaderID)->getShader()->setUniformValue("texture", 0);

        //Draw
        gl->glDrawArrays(GL_TRIANGLES, 0, materials->getVAO(strSets.at(i)->vaoID)->getNumVertices()); //num of verticies
        //Unbind
        materials->getVAO(strSets.at(i)->vaoID)->unbind();
        materials->getTexture(textureID)->unbind();
        materials->getShader(shaderID)->unbind();
    }
}


void Font::addString(QString str, float xPos, float yPos)
{
    //Converts string to verticies and texture coordinates.
    float cursorX = 0;
    float cursorY = 0;

    //Max Height
    float maxHeight = 0;

    vector<GLfloat> vertices;
    vector<GLfloat> texCoords;
    int numVertices = 0;

    //For Each character
    for(int i=0; i < str.size(); i++)
    {

        //Iterate through chars to find font info for character
        for(int j = 0; j < charCount; j++)
        {


            //Found font info for character
            if(str.at(i).unicode() == chars[j].id)
            {

                //qDebug() << "--------------------";
                //qDebug() << "ID: " << chars[j].id;
                //qDebug() << "V: " << chars[j].xoffset_vert << "," << chars[j].yoffset_vert;
                //qDebug() << "UV: " << chars[j].x_tex << "," << chars[j].y_tex;
                //qDebug() << "PAD: " << padX << "," << padY;
                //qDebug() << "xAdv: " << chars[j].xadvance_vert;


                //Top Left Vertex
                vertices.push_back(cursorX + chars[j].xoffset_vert);
                vertices.push_back(cursorY - chars[j].yoffset_vert);
                texCoords.push_back(chars[j].x_tex + padX/2.0f);
                texCoords.push_back(chars[j].y_tex + padY/2.0f);
                //Bottom Left Vertex
                vertices.push_back(cursorX + chars[j].xoffset_vert);
                vertices.push_back(cursorY - chars[j].yoffset_vert - chars[j].char_height_vert);
                texCoords.push_back(chars[j].x_tex + padX/2.0f);
                texCoords.push_back(chars[j].y_tex + padY/2.0f + chars[j].char_height_tex);
                //Top Right Vertex
                vertices.push_back(cursorX + chars[j].xoffset_vert + chars[j].char_width_vert);
                vertices.push_back(cursorY - chars[j].yoffset_vert);
                texCoords.push_back(chars[j].x_tex + padX/2.0f + chars[j].char_width_tex);
                texCoords.push_back(chars[j].y_tex + padY/2.0f);

                //Top Right Vertex
                vertices.push_back(cursorX + chars[j].xoffset_vert + chars[j].char_width_vert);
                vertices.push_back(cursorY - chars[j].yoffset_vert);
                texCoords.push_back(chars[j].x_tex + padX/2.0f + chars[j].char_width_tex);
                texCoords.push_back(chars[j].y_tex + padY/2.0f);
                //Bottom Left Vertex
                vertices.push_back(cursorX + chars[j].xoffset_vert);
                vertices.push_back(cursorY - chars[j].yoffset_vert - chars[j].char_height_vert);
                texCoords.push_back(chars[j].x_tex + padX/2.0f);
                texCoords.push_back(chars[j].y_tex + padY/2.0f + chars[j].char_height_tex);
                //Bottom Right Vertex
                vertices.push_back(cursorX + chars[j].xoffset_vert + chars[j].char_width_vert);
                vertices.push_back(cursorY - chars[j].yoffset_vert - chars[j].char_height_vert);
                texCoords.push_back(chars[j].x_tex + padX/2.0f + chars[j].char_width_tex);
                texCoords.push_back(chars[j].y_tex + padY/2.0f + chars[j].char_height_tex);

                numVertices += 12;
                cursorX = cursorX + chars[j].xadvance_vert;

                //Max Height
                maxHeight = max(maxHeight, chars[j].char_height_vert);

                //break out of for loop to go to next character
                break;
            }
        }

    }
    /*****************************************************************************/

    //Creates VAO with vertices and texture coordinates
    //Create VAO
    VAO* vao = new VAO();
    unsigned int stringVAO = materials->addVAO(vao);
    materials->getShader(shaderID)->bind();
    materials->getVAO(stringVAO)->bind();
    materials->getVAO(stringVAO)->setNumVertices(numVertices);
        //Create VBOs
        //Vertices
        VBO* stringVBO_Vertices = new VBO(&vertices[0]
                , numVertices * 2 * static_cast<int>(sizeof(GLfloat))
                , QOpenGLBuffer::StaticDraw);
        stringVBO_Vertices->bind();
        materials->getShader(shaderID)->setAttributePointer("position", GL_FLOAT, 0, 2, sizeof(GLfloat) * 2);
        //Texture Coordinates
        VBO* stringVBO_texCoords = new VBO(&texCoords[0]
                , numVertices * 2 * static_cast<int>(sizeof(GLfloat))
                , QOpenGLBuffer::StaticDraw);
        stringVBO_texCoords->bind();
        materials->getShader(shaderID)->setAttributePointer("texCoords", GL_FLOAT, 0, 2, sizeof(GLfloat) * 2);
    //unbind VAO
    materials->getVAO(stringVAO)->unbind();
    //unbind VBOs
    stringVBO_Vertices->unbind();
    stringVBO_texCoords->unbind();
    //unbind Shader Program
    materials->getShader(shaderID)->unbind();
    /*****************************************************************************/

    //Create String Set
    StringSet *set = new StringSet();
    set->vaoID = stringVAO;
    set->numVertices = numVertices;
    set->xPos = xPos;
    set->yPos = yPos;
    set->width = cursorX;
    set->height = maxHeight;

    //Add to strSets to be ready for rendering
    strSets.push_back(set);
}

void Font::loadFont(QString fontPath)
{
    float size = 500.0f;

    //Load FontFile from path
    QFile fontFile(fontPath);
    if(!fontFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not load text file at location: " << fontPath << endl;
    }

    QTextStream in(&fontFile);


    /************************Convert Txt File to chars Array**********************/

    //Used to hold all characters info
    chars = nullptr;

    //Pulls important data to render text from font file.
    while(!in.atEnd())
    {

        QString line = in.readLine();
        QStringList lineList = line.split(" ");

        //Important Line Types
        if(lineList.at(0).compare("info")== 0)
        {
            //Iterate through each word in the line expluding the first
            for(int i=1; i < lineList.size(); i++){
                //Split each word
                QStringList wordSplit = lineList.at(i).split("=");
                //Important Word Types
                if(wordSplit.at(0).compare("padding") == 0)
                {
                    //Split to get Values
                    QStringList valueSplit = wordSplit.at(1).split(",");
                    for(int j=0; j < valueSplit.size(); j++){
                        padX = valueSplit.at(j).toFloat();
                        padY = valueSplit.at(j).toFloat();
                    }
                }
            }
        }
        else if(lineList.at(0).compare("common")== 0)
        {
            for(int i=1; i < lineList.size(); i++){
                QStringList wordSplit = lineList.at(i).split("=");
                if(wordSplit.at(0).compare("lineHeight") == 0)
                {
                    lineHeight = wordSplit.at(1).toFloat();
                }
                else if(wordSplit.at(0).compare("scaleW") == 0)
                {
                    imgWidth = wordSplit.at(1).toFloat();
                    padX = padX / imgWidth;
                }
                else if(wordSplit.at(0).compare("scaleH") == 0)
                {
                    imgHeight = wordSplit.at(1).toFloat();
                    padY = padY / imgHeight;
                }
            }
        }
        else if(lineList.at(0).compare("chars")== 0)
        {
            for(int i=1; i < lineList.size(); i++){
                QStringList wordSplit = lineList.at(i).split("=");
                if(wordSplit.at(0).compare("count") == 0)
                {
                    //Declares an array with size of chars count.
                    chars = new fChar[wordSplit.at(1).toInt()];
                }
            }
        }
        else if(lineList.at(0).compare("char")== 0)
        {
            for(int i=1; i < lineList.size(); i++)
            {
                QStringList wordSplit = lineList.at(i).split("=");
                if(wordSplit.at(0).compare("id") == 0)
                {
                    chars[charCount].id = wordSplit.at(1).toUShort();
                }
                else if(wordSplit.at(0).compare("x") == 0)
                {
                    chars[charCount].x_tex = wordSplit.at(1).toFloat() / imgWidth;
                }
                else if(wordSplit.at(0).compare("y") == 0)
                {
                    chars[charCount].y_tex = wordSplit.at(1).toFloat() / imgHeight;
                }
                else if(wordSplit.at(0).compare("width") == 0)
                {
                    chars[charCount].char_width_vert = wordSplit.at(1).toFloat() / size;
                    chars[charCount].char_width_tex = wordSplit.at(1).toFloat() / imgWidth;
                }
                else if(wordSplit.at(0).compare("height") == 0)
                {
                    chars[charCount].char_height_vert = wordSplit.at(1).toFloat() / size;
                    chars[charCount].char_height_tex = wordSplit.at(1).toFloat() / imgHeight;
                }
                else if(wordSplit.at(0).compare("xoffset") == 0)
                {
                    chars[charCount].xoffset_vert = wordSplit.at(1).toFloat() / size;
                }
                else if(wordSplit.at(0).compare("yoffset") == 0)
                {
                    chars[charCount].yoffset_vert = wordSplit.at(1).toFloat() / size;
                }
                else if(wordSplit.at(0).compare("xadvance") == 0)
                {
                    chars[charCount].xadvance_vert = wordSplit.at(1).toFloat() / size;
                }
            }
            charCount++;
        }
    }

    fontFile.close();
    /*****************************************************************************/
}
