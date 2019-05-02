#ifndef VAO_H
#define VAO_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>

/*
 * Description: VAO is a buffer that is used to store multiple VBO's.
 *              the VAO will need to be bound before draw calls.
 *
 * Author: Nick
 *
 */

class VAO
{
public:
    VAO();
    ~VAO();
    void bind();
    void unbind();
    QOpenGLVertexArrayObject* getVAO();
    void setNumVertices(int numVertices);
    int getNumVertices();
protected:

private:
    QOpenGLVertexArrayObject* vao = new QOpenGLVertexArrayObject();
    int numVertices = 0;
};

#endif // VAO_H
