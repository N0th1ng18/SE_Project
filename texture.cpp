#include "texture.h"

Texture::Texture()
{

}
Texture::Texture(const QString filePath)
{
    // Load Texture
    QImage *image = new QImage(filePath);
    if(image->isNull()){
        qDebug("Failed to load texture.");
        return;
    }

    this->texture = new QOpenGLTexture(image->mirrored());
}

Texture::~Texture()
{
    delete texture;
    texture = nullptr;
}


void Texture::bind()
{
    texture->bind();
}

void Texture::unbind()
{
    texture->release();
}

void Texture::setMiniFilter(QOpenGLTexture::Filter type)
{
    texture->setMinificationFilter(type);
}
void Texture::setMagFilter(QOpenGLTexture::Filter type)
{
    texture->setMagnificationFilter(type);
}
void Texture::setWrapMode(QOpenGLTexture::WrapMode mode)
{
    texture->setWrapMode(mode);
}

QOpenGLTexture* Texture::getTexture()
{
    return texture;
}
