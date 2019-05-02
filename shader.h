#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

/*
 * Description: Shader is used to store the gpu programs.
 *
 * Author: Nick
 *
 */

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
    QOpenGLShaderProgram* getShader();

protected:

private:
    QOpenGLShaderProgram *program = new QOpenGLShaderProgram();

};

#endif // SHADER_H
