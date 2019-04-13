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
    glClearColor(0, 1, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    //Load Materials

    timer.start(12, this);
}

void OpenGLWindow::loadMaterials(){
    //Textures
    Texture *texture0 = new Texture(":test.png");
    texture0->setMiniFilter(QOpenGLTexture::Nearest);
    texture0->setMagFilter(QOpenGLTexture::Linear);
    texture0->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture0);
    delete texture0;

    //Shaders
    Shader *shader = new Shader(":/vertex_Desktop.vsh", ":/frag_Desktop.fsh");
    materials->addShader(shader);
    delete shader;

    //Models
    Model *model = new Model();
    materials->addModel(model);
    delete model;

    //VAOs
    DO VAO AND VBOS AND WE DONE!!
}


void OpenGLWindow::initShaders()
{

    /*******************************************************************/

    //Create VAO with all VBOs
    vao.create();
    vao.bind();

    //Create VBO for Vertices
    vertex_VBO.create();
    vertex_VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertex_VBO.bind();
    vertex_VBO.allocate(&vertices[0], 18 * sizeof(GLfloat));
    program.enableAttributeArray("position");
    program.setAttributeBuffer("position", GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);    //Stride is size to next set of attributes

    //Create VBO for Textures
    texCoords_VBO.create();
    texCoords_VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    texCoords_VBO.bind();
    texCoords_VBO.allocate(&texCoords[0], 12 * sizeof(GLfloat));
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
    glDrawArrays(GL_TRIANGLES, 0, 6); //num of verticies

    //Unbind
    textures[0]->release();
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


