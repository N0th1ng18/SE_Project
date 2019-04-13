#include "vao.h"

VAO::VAO()
{
    //Create VAO
    vao->create();
}

VAO::~VAO()
{
    vao->~QOpenGLVertexArrayObject();
    delete vao;
    vao = nullptr;
}

//Bind VAO
void VAO::bind()
{
    vao->bind();
}

//Unbind VAO
void VAO::unbind()
{
    vao->release();
}

//Returns the VAO
QOpenGLVertexArrayObject* VAO::getVAO()
{
    return vao;
}
