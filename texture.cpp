#include "texture.h"

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

QOpenGLTexture* Texture::getTexture()
{
    return texture;
}
