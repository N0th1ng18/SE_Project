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
    texCoords_VBO.destroy();
    vao.destroy();
    delete *textures;
    /*-------*/
    doneCurrent();
}


void OpenGLWindow::timerEvent(QTimerEvent *)
{


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
    initTextures();
    //loadObjects(QOpenGLShaderProgram program)

    timer.start(12, this);
}

void OpenGLWindow::initTextures()
{

    // Load Wood Texture
    QImage *image = new QImage(":wood.png");
    if(image->isNull()){
        qDebug() << "Failed to load image0.";
        return;
    }
    textures[0] = new QOpenGLTexture(image->mirrored());
    textures[0]->setMinificationFilter(QOpenGLTexture::Nearest);
    textures[0]->setMagnificationFilter(QOpenGLTexture::Linear);
    textures[0]->setWrapMode(QOpenGLTexture::Repeat);
    /*******************************************************************/

}

void OpenGLWindow::initShaders()
{
    //qDebug() << "initShaders";

    /* Desktop Version:
     * Compile vertex_Desktop & frag_Desktop
     *
     * Android Version:
     * Compile vertex_Android & frag_Android
     */

    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex_Desktop.vsh"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/frag_Desktop.fsh"))
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

    /*******************************************************************/

    //Vertex Positions
    GLfloat vertices[] = {
           -1.0f, -1.0f, 0.0f,
           1.0f, -1.0f, 0.0f,
           0.0f, 1.0f, 0.0f
       };

    //Vertex Texture Coords
    GLfloat texCoords[] = {
           0.0f, 0.0f,
           1.0f, 0.0f,
           0.5f, 1.0f,
       };
    /*******************************************************************/

    //Create VAO with all VBOs
    vao.create();
    vao.bind();

    //Create VBO for Vertices
    vertex_VBO.create();
    vertex_VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertex_VBO.bind();
    vertex_VBO.allocate(vertices, 9 * sizeof(GLfloat));
    program.enableAttributeArray("position");
    program.setAttributeBuffer("position", GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);    //Stride is size to next set of attributes

    //Create VBO for Textures
    texCoords_VBO.create();
    texCoords_VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    texCoords_VBO.bind();
    texCoords_VBO.allocate(texCoords, 6 * sizeof(GLfloat));
    program.enableAttributeArray("texCoords");
    program.setAttributeBuffer("texCoords", GL_FLOAT, 0, 2, sizeof(GLfloat) * 2);    //Stride is size to next set of attributes


    //Unbind VBOs
    vertex_VBO.release();
    texCoords_VBO.release();
    //Unbind VAO
    vao.release();
    //Unbind Shader Program
    program.release();
    /*******************************************************************/
}

void OpenGLWindow::resizeGL(int w, int h)
{
    //qDebug() << "resizeGL";
    g_width = w;
    g_height = h;

    glViewport(0,0,w,h);

    float width = static_cast<float>(w);
    float height = static_cast<float>(h);
    g_aspectRatio = width/height;


    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(90.0f, g_aspectRatio, 0.1f, 100.0f);

}

void OpenGLWindow::paintGL()
{
    //qDebug() << "paintGL";

    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Render Entities
    //Bind Shader
    program.bind();
    //Bind VAO
    vao.bind();
    //Bind Textures
    textures[0]->bind();

    //Interpolate

    //Transformation
    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, -2.0f);
    transformationMatrix.setToIdentity();

    //Uniforms
    program.setUniformValue("projectionMatrix", projectionMatrix);
    program.setUniformValue("viewMatrix", viewMatrix);
    program.setUniformValue("transformationMatrix", transformationMatrix);
    program.setUniformValue("texture", 0);

    //Draw
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //Unbind
    vao.release();
    program.release();
    /*******************************************************************/

    //Render Text
    int textPosX = 0;
    int textPosY = -130;
    int fontSize = 20;
    std::string str = "Software Engineering Project";
    QString text = QString::fromStdString(str);

    //Set up Painter
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Helvetica", fontSize));
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    //Font Metrics
    QFontMetrics metrics = painter.fontMetrics();
    //Text Position
    textPosX = textPosX - metrics.width(text)/2 + g_width / 2;
    textPosY = textPosY + g_height / 2;
    //Draw Text
    painter.drawText(textPosX, textPosY, text);
    painter.end();
    /*******************************************************************/
}


