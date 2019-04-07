#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWidget *parent) :
    QOpenGLWidget(parent)
{
    //qDebug("OpenGLWindow Constructor");
}

OpenGLWindow::~OpenGLWindow()
{
    makeCurrent();
    /*Clean Up*/
    vertex_VBO.destroy();
    vao.destroy();
    /*-------*/
    doneCurrent();
}


void OpenGLWindow::timerEvent(QTimerEvent *)
{

     //update();
}

void OpenGLWindow::initializeGL()
{
    //qDebug() << "initializeGL";
    initializeOpenGLFunctions();

    //OpenGL Settings
    glClearColor(1, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    initShaders();

    timer.start(12, this);
}

void OpenGLWindow::initShaders()
{
    //qDebug() << "initShaders";
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
           -1.0f, -1.0f, 0.0f,
           1.0f, -1.0f, 0.0f,
           0.0f, 1.0f, 0.0f
       };

    //Create VAO
    vao.create();
    vao.bind();

    //Create VBO for Vertices
    vertex_VBO.create();
    vertex_VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertex_VBO.bind();
    vertex_VBO.allocate(vertices, 9 * sizeof(GLfloat));
    program.enableAttributeArray("position");
    program.setAttributeBuffer("position", GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);    //Stride is size to next set of attributes

    //Unbind VBOs and VAO and Shader Program
    vertex_VBO.release();
    vao.release();
    program.release();
}

void OpenGLWindow::resizeGL(int w, int h)
{
    //qDebug() << "resizeGL";

    glViewport(0,0,w,h);

    float width = static_cast<float>(w);
    float height = static_cast<float>(h);
    float aspectRatio = width/height;


    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(90.0f, aspectRatio, 0.1f, 100.0f);

}

void OpenGLWindow::paintGL()
{
    //qDebug() << "paintGL";

    //bind Shader
    program.bind();

    //Bind VAO
    vao.bind();

    //Bind Textures

    //Interpolate

    //Transformation
    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, -2.0f);
    transformationMatrix.setToIdentity();

    //Uniforms
    program.setUniformValue("projectionMatrix", projectionMatrix);
    program.setUniformValue("viewMatrix", viewMatrix);
    program.setUniformValue("transformationMatrix", transformationMatrix);

    //Draw
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //Unbind
    vao.release();
    program.release();
}


