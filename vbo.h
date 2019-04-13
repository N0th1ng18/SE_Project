#ifndef VBO_H
#define VBO_H

#include <QOpenGLBuffer>

class VBO
{
public:
    VBO();
    VBO(const void* data, int sizeInBytes, QOpenGLBuffer::UsagePattern typeDraw);
    ~VBO();
    void bind();
    void unbind();
    QOpenGLBuffer* getVBO();

protected:

private:
    QOpenGLBuffer* vbo;
};

#endif // VBO_H
