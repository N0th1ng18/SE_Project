#ifndef TEXTURE_H
#define TEXTURE_H

#include <QOpenGLFunctions>
#include <QOpenGLTexture>

class Texture
{
public:
    Texture(const QString filePath);
    ~Texture();
    void bind();
    void unbind();
    QOpenGLTexture* getTexture();

protected:

private:
    QOpenGLTexture texture;
};

#endif // TEXTURE_H
