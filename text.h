#ifndef TEXT_H
#define TEXT_H

#include <QPainter>

class Text
{
public:
    Text(std::string str, int x, int y, int z, std::string font, int fontSize);
    ~Text();

    void update();
    void render(QPainter* painter);

private:
    int x, y, z;
    QString str;
    QString font;
    int fontSize;

};

#endif // TEXT_H
