#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

class Shader
{
public:
    Shader(const QString vertexShaderPath, const QString fragmentShaderPath);
    ~Shader();
    void link();
    void bind();
    void unbind();
    void setAttributePointer(const char *name
                             , GLenum type
                             , int offset
                             , int vectorSize
                             , int bytesToNextVector);
    QOpenGLShaderProgram* getProgram();

protected:

private:
    QOpenGLShaderProgram program;

};

#endif // SHADER_H
