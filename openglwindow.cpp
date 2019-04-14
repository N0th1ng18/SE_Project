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

    delete materials;
    materials = nullptr;

    delete clientState;
    clientState = nullptr;

    /*-------*/
    doneCurrent();
}

void OpenGLWindow::initializeGL()
{
    //qDebug() << "initializeGL";
    initializeOpenGLFunctions();
    gl = QOpenGLContext::currentContext()->functions();

    //OpenGL Settings
    glClearColor(0, 1, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    //Load Materials
    loadMaterials();
    loadEntities();

    //timer.start(12, this);
    timer.start(1000, this);
}

void OpenGLWindow::loadMaterials()
{
    //Models
    Model *model = new Model();

    //Textures
    Texture *texture0 = new Texture(":test.png");
    texture0->setMiniFilter(QOpenGLTexture::Nearest);
    texture0->setMagFilter(QOpenGLTexture::Linear);
    texture0->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture0);

    //Shaders
    Shader *shader = new Shader(":/vertex_Desktop.vsh", ":/frag_Desktop.fsh");
    //Shader *shader = new Shader(":/vertex_Android.vsh", ":/frag_Android.fsh");
    unsigned int defaultShader = materials->addShader(shader);

    //VAOs
    VAO *vao = new VAO();
    unsigned int squareVAO = materials->addVAO(vao);


    /*Setup Square VAO*/
    materials->getShader(defaultShader)->bind();
    materials->getVAO(squareVAO)->bind();
    materials->getVAO(squareVAO)->setNumVertices(model->getNumVertices());
    /*Setup Square VBOs*/
        //Vertices Buffer
        VBO *vbo_Vertices = new VBO(&model->getVertices()[0]
                , model->getNumVertices() * 3 * static_cast<int>(sizeof(GLfloat))
                , QOpenGLBuffer::StaticDraw);
        vbo_Vertices->bind();
        materials->getShader(defaultShader)->setAttributePointer("position", GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);
        //Texture Coordinates Buffer
        VBO *vbo_texCoords  = new VBO(&model->getTexCoords()[0]
                , model->getNumVertices() * 2 * static_cast<int>(sizeof(GLfloat))
                , QOpenGLBuffer::StaticDraw);
        vbo_texCoords->bind();
        materials->getShader(defaultShader)->setAttributePointer("texCoords", GL_FLOAT, 0, 2, sizeof(GLfloat) * 2);


    //unbind VBOs
    vbo_Vertices->unbind();
    vbo_texCoords->unbind();
    //unbind VAO
    materials->getVAO(squareVAO)->unbind();
    //unbind Shader Program
    materials->getShader(defaultShader)->unbind();

    //Clean UP
    delete vbo_Vertices;
    delete vbo_texCoords;
    delete model;
}

void OpenGLWindow::loadEntities()
{
    //Create Objects, Players, Sounds, etc.
    //Server should do this and send it to client.
    //This is only useful for miniGames.

    clientState->addObject(materials, 0, 0, 0);
}

void OpenGLWindow::timerEvent(QTimerEvent *)
{

    clientState->update();

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

    //Camera
    materials->getShader(0)->bind();
    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, -2.0f);
    materials->getShader(0)->getShader()->setUniformValue("projectionMatrix", projectionMatrix);
    materials->getShader(0)->getShader()->setUniformValue("viewMatrix", viewMatrix);
    materials->getShader(0)->unbind();

    //Render clientState
    clientState->render(gl);

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


