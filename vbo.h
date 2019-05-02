#ifndef VBO_H
#define VBO_H

#include <QOpenGLBuffer>

/*
 * Description: VBO is a buffer that stores attributes(Verts, textcoords, etc.)
 *
 *  Author: Nick
*/

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
    QOpenGLBuffer* vbo = new QOpenGLBuffer();
};

#endif // VBO_H
