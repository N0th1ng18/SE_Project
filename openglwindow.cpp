#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWidget *parent) :
    QOpenGLWidget(parent)
{
    //qDebug("OpenGLWindow Constructor");
    makeCurrent();
    initializeGL();
}

OpenGLWindow::~OpenGLWindow()
{
    makeCurrent();
    /*Clean Up*/

    /*--------*/
    doneCurrent();
}


void OpenGLWindow::initializeGL()
{
    //qDebug() << "initializeGL";
    initializeOpenGLFunctions();

    //OpenGL Settings
    glClearColor(1, 0, 0, 1);
    //glEnable(GL_CULL_FACE);

    initShaders();

}

void OpenGLWindow::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex.vsh"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/frag.fsh"))
        close();

    // Link shader pipeline
    if (!program.link())
    {
        qDebug() << "Failed to link shader program";
        close();
    }

    // Bind shader pipeline for use
    if (!program.bind())
    {
        qDebug() << "Failed to bind shader program";
        close();
    }

    //Create VAO with all VBOs
    GLfloat vertices[] = {
           0.0f, 0.707f, 0.0f,
           -0.5f, -0.5f, 0.0f,
           0.5f, -0.5f, 0.0f
       };

    //Create VAO
    vao.create();
    vao.bind();

    //Create VBO for Vertices
    vertex_VBO.create();
    vertex_VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertex_VBO.bind();
    vertex_VBO.allocate(vertices, 12 * sizeof(float));
    program.enableAttributeArray("position");
    program.setAttributeBuffer("position", GL_FLOAT, 0, 3, sizeof(GLfloat));

    //Unbind VBOs and VAO
    vertex_VBO.release();
    vao.release();

    //Unbind Shader Program
    program.release();
}

void OpenGLWindow::resizeGL(int w, int h)
{
    qDebug() << "resizeGL";

    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float aspectRatio = static_cast<float>(w)/static_cast<float>(h);

    orthoMatrix.setToIdentity();
    orthoMatrix.ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, 0.1f, 100.0f);
}

void OpenGLWindow::paintGL()
{
    qDebug() << "paintGL";

    //bind Shader
    program.bind();

    //Bind VAO
    vao.bind();

    //Bind Textures

    //Interpolate

    //Transformation
    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, 0.0f);
    transformationMatrix.setToIdentity();

    //Uniforms
    program.setUniformValue("orthoMatrix", orthoMatrix);
    program.setUniformValue("viewMatrix", viewMatrix);
    program.setUniformValue("transformationMatrix", transformationMatrix);

    //Draw
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //Unbind
    vao.release();
    program.release();
}


