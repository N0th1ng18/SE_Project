#include "shader.h"

Shader::Shader(const QString vertexShaderPath, const QString fragmentShaderPath)
{
    // Compile vertex shader
    //":/vertex_Desktop.vsh"
    if (!program->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath))
    {
        qDebug("Failed To Compile VertexShader");
    }


    // Compile fragment shader
    //":/frag_Desktop.fsh"
    if (!program->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath))
    {
        qDebug("Failed To Compile FragmentShader");
    }

    // Link shader pipeline
    if (!program->link())
    {
        qDebug("Failed To Link Shader Program");
    }

    // Bind shader pipeline for use
    if (!program->bind())
    {
        qDebug("Failed To Bind Shader Program");
    }

    program->release();
}

Shader::~Shader()
{
    program->~QOpenGLShaderProgram();
    delete program;
}

void Shader::link()
{
    // Link shader pipeline
    if (!program->link())
    {
        qDebug("Failed To Link Shader Program");
    }
}

void Shader::bind()
{
    // Bind shader pipeline for use
    if (!program->bind())
    {
        qDebug("Failed To Bind Shader Program");
    }
}

void Shader::unbind()
{
    program->release();
}

void Shader::setAttributePointer(const char *name, GLenum type, int offset, int vectorSize, int bytesToNextVector)
{
    //const char *name, GLenum type, int offset, int tupleSize, int stride = 0
    program->enableAttributeArray(name);
    program->setAttributeBuffer(name, type, offset, vectorSize, bytesToNextVector);
}



QOpenGLShaderProgram* Shader::getShader()
{
    return program;
}
