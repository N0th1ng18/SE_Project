#include "vbo.h"

VBO::VBO(){
    vbo->create();
}

VBO::VBO(const void* data, int sizeInBytes, QOpenGLBuffer::UsagePattern typeDraw)
{
    vbo->create();
    vbo->setUsagePattern(typeDraw);
    vbo->bind();
    vbo->allocate(data, sizeInBytes);
    vbo->release();
}

VBO::~VBO()
{
    vbo->~QOpenGLBuffer();
    delete vbo;
    vbo = nullptr;
}

void VBO::bind()
{
    vbo->bind();
}
void VBO::unbind()
{
    vbo->release();
}

QOpenGLBuffer* VBO::getVBO()
{
    return vbo;
}
