#include "text.h"

Text::Text(std::string str, int x, int y, int z, std::string font, int fontSize)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->str = QString::fromStdString(str);
    this->font = QString::fromStdString(font);
    this->fontSize = fontSize;
}

Text::~Text()
{

}

void Text::update()
{

}
void Text::render(QPainter* painter)
{
    //Need to change this to the traditional Opengl text rendering
    //for it to work on android. will need shaders, etc...

    //Set up Painter
    painter->setPen(Qt::blue);
    painter->setFont(QFont(font, fontSize));
    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    //Font Metrics
    //QFontMetrics metrics = painter->fontMetrics();
    //Text Position
    //textPosX = textPosX - metrics.width(text)/2 + g_width / 2;
    //textPosY = textPosY + g_height / 2;
    //Draw Text
    painter->drawText(x, y, str);
    /*******************************************************************/
}
