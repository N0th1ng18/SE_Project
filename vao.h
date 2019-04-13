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

protected:

private:
    QOpenGLVertexArrayObject* vao;

};

#endif // VAO_H
