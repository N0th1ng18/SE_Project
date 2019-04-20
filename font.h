#ifndef TEXT_H
#define TEXT_H

#include <qstring.h>
#include <qfile.h>
#include <QtDebug>

class Font
{
public:
    Font();
    ~Font();
    void loadFont(QString filePath);
};

#endif // TEXT_H
