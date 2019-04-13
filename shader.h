#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <string>

class Shader
{
public:
    Shader(const QString vertexShaderPath, const QString fragmentShaderPath);
    ~Shader();
    void link();
    void bind();
    void unbind();
    QOpenGLShaderProgram* getProgram();

protected:

private:
    QOpenGLShaderProgram program;

};

#endif // SHADER_H
