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
    Texture *texture0 = new Texture(":guy1.png");
    texture0->setMiniFilter(QOpenGLTexture::Nearest);
    texture0->setMagFilter(QOpenGLTexture::Linear);
    texture0->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture0);

    Texture *texture1 = new Texture(":guy2.png");
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture1);


    //Shaders
    Shader *shader = nullptr;
    if(QSysInfo::currentCpuArchitecture().compare("x86_64") == 0)
    {
        shader= new Shader(":/vertex_Desktop.vsh", ":/frag_Desktop.fsh");
    }else if(QSysInfo::currentCpuArchitecture().compare("arm64") == 0){
        shader = new Shader(":/vertex_Android.vsh", ":/frag_Android.fsh");
    }else{
        shader = new Shader(":/vertex_Android.vsh", ":/frag_Android.fsh");
    }
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

    //Sounds
    Sound* backgroundMusic = new Sound();
    backgroundMusic->load("qrc:/sounds/lobby_song.mp3");
    backgroundMusic->setVolume(90);
    backgroundMusic->play(0);

    //Text
    Font* arial = new Font();
    arial->loadFont(":/Fonts/Fonts/Arial/Arial.fnt");

    //Cameras
    Camera *cam = new Camera(materials, 0, new QVector3D(0.0f, 0.0f, -2.0f));
    clientState->addCamera(cam);
    clientState->setActiveCamera(0);

    //Objects
    Object *obj = new Object(materials, 0, 0, 1, new QVector3D(-1.0f, 0.0f, 0.0f));
    clientState->addObject(obj);
    Object *obj2 = new Object(materials, 0, 0, 0, new QVector3D(1.0f, 0.0f, 0.0f));
    clientState->addObject(obj2);

    //Text

    /*
     * Need to change this to the traditional Opengl text rendering
     * for it to work on android. will need shaders, etc...
    */

    //clientState->addText(new Text("Jungle Escape", this->width()/2, this->height()/2, 0, "Helvetica", 20));
    //clientState->addText(new Text("Some Text", this->width()/2, this->height()/2 + 20, 0, "Helvetica", 20));
    //clientState->addText(new Text("Some More Text", this->width()/2, this->height()/2+40, 0, "Helvetica", 20));



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
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    clientState->getProjection()->setToIdentity();
    clientState->getProjection()->perspective(90.0f, g_aspectRatio, 0.1f, 100.0f);

}

void OpenGLWindow::paintGL()
{
    //qDebug() << "paintGL";
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Render clientState
    clientState->render(gl);
}




