#include "font.h"

struct fChar{
    int id;
    int x;
    int y;
    int width;
    int height;
    int xoffset;
    int yoffset;
    int xadvance;
};

Font::Font()
{

}

Font::~Font()
{

}

void Font::loadFont(QString fontPath)
{

    //Load FontFile from path
    QFile fontFile(fontPath);
    if(!fontFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not load text file at location: " << fontPath << endl;
    }

    QTextStream in(&fontFile);

    //Global Character and Image Settings
    int paddingL;
    int paddingR;
    int paddingU;
    int paddingD;
    int lineHeight;
    int imgWidth;
    int imgHeight;

    /************************Convert Txt File to chars Array**********************/

    //Used to hold all characters info
    fChar* chars = nullptr;
    //Keeps track of the number of characters in Font
    int charCount = 0;

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
                        paddingL = valueSplit.at(j).toInt();
                        paddingR = valueSplit.at(j).toInt();
                        paddingU = valueSplit.at(j).toInt();
                        paddingD = valueSplit.at(j).toInt();
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
                    lineHeight = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("scaleW") == 0)
                {
                    imgWidth = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("scaleH") == 0)
                {
                    imgHeight = wordSplit.at(1).toInt();
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
        else if(lineList.at(0).compare("char")== 0) // && chars checks to make sure pointer is not null
        {
            for(int i=1; i < lineList.size(); i++)
            {
                QStringList wordSplit = lineList.at(i).split("=");
                if(wordSplit.at(0).compare("id") == 0)
                {
                    chars[charCount].id = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("x") == 0)
                {
                    chars[charCount].x = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("y") == 0)
                {
                    chars[charCount].y = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("width") == 0)
                {
                    chars[charCount].width = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("height") == 0)
                {
                    chars[charCount].height = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("xoffset") == 0)
                {
                    chars[charCount].xoffset = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("yoffset") == 0)
                {
                    chars[charCount].yoffset = wordSplit.at(1).toInt();
                }
                else if(wordSplit.at(0).compare("xadvance") == 0)
                {
                    chars[charCount].xadvance = wordSplit.at(1).toInt();
                }
            }

            charCount++;
        }
    }

    fontFile.close();
    /*****************************************************************************/

    //Use Array of chars to construct vertices and texture coordinates.

}
