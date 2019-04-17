#ifndef VAO_H
#define VAO_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>


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
