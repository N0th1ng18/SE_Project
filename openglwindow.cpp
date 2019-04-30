#include "openglwindow.h"


OpenGLWindow::OpenGLWindow(QString userName, QString address, quint16 port, QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->userName = userName;
    this->address = address;
    this->port = port;
    qDebug() << "OpenGLConstructor";
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
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    qDebug() << "OpenGLinitialized";

    connectToServer();
    loadMaterials();
    loadEntities();

    timer.start(12, this);
}

void OpenGLWindow::connectToServer()
{
    //Use Address and password to connect
    qDebug() << "Pre socketP creation";
    socketP = new ClientGameProtocol(this->userName, clientState);
    //socketP->connect(socketP, SIGNAL(started()), socketP, SLOT(setup()));
    socketP->setup();
    socketP->connectGameServer(this->address, this->port);

    //Test game connected -> try again or go back to qml

    qDebug() << "Post socketP Connect to Server";


}

void OpenGLWindow::loadMaterials()
{
    //Models
    Model *model = new Model();


    //Textures
    Texture *texture0 = new Texture(":Map0.png", false, true);
    texture0->setMiniFilter(QOpenGLTexture::Nearest);
    texture0->setMagFilter(QOpenGLTexture::Linear);
    texture0->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture0);

    Texture *texture1 = new Texture(":Fox.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture1);

    Texture *texture2 = new Texture(":Bear.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture2);

    Texture *texture3 = new Texture(":Deer.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture3);

    Texture *texture4 = new Texture(":Butterfly.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture4);

    Texture *texture5 = new Texture(":Owl.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture5);

    Texture *texture6 = new Texture(":Frog.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture6);

    Texture *texture7 = new Texture(":Rabbit.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture7);

    Texture *texture8 = new Texture(":Squirrel.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture8);

    //Fonts

    Texture *texture9 = new Texture(":/Fonts/Fonts/Arial/Arial.png", false, false);
    texture2->setMiniFilter(QOpenGLTexture::Nearest);
    texture2->setMagFilter(QOpenGLTexture::Linear);
    texture2->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture9);

    //Buttons
    Texture *texture10 = new Texture(":arrow_unclicked.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture10);

    Texture *texture11 = new Texture(":arrow_clicked.png", false, true);
    texture1->setMiniFilter(QOpenGLTexture::Nearest);
    texture1->setMagFilter(QOpenGLTexture::Linear);
    texture1->setWrapMode(QOpenGLTexture::Repeat);
    materials->addTexture(texture11);

    //Shaders
    Shader* shader0 = nullptr;
    Shader* shader1 = nullptr;
    if(QSysInfo::currentCpuArchitecture().compare("x86_64") == 0)
    {
        //PC
        shader0= new Shader(":/vertex_Desktop.vsh", ":/frag_Desktop.fsh");
        shader1= new Shader(":/vertex_Text_Desktop.vsh", ":/frag_Text_Desktop.fsh");
    }
    else if(QSysInfo::currentCpuArchitecture().compare("arm64") == 0)
    {
        //Android
        shader0 = new Shader(":/vertex_Android.vsh", ":/frag_Android.fsh");
        shader1= new Shader(":/vertex_Text_Android.vsh", ":/frag_Text_Android.fsh");

    }
    else
    {
        //Unknown
        shader0 = new Shader(":/vertex_Android.vsh", ":/frag_Android.fsh");
        shader1= new Shader(":/vertex_Text_Android.vsh", ":/frag_Text_Android.fsh");

    }
    unsigned int defaultShader = materials->addShader(shader0);
    materials->addShader(shader1);


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

    //unbind VAO
    materials->getVAO(squareVAO)->unbind();
    //unbind VBOs
    vbo_Vertices->unbind();
    vbo_texCoords->unbind();
    //unbind Shader Program
    materials->getShader(defaultShader)->unbind();

    //Add materials pointer to ClientGameProtocol
    this->socketP->setMaterials(materials);

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

    //Cameras
    Camera* cam = new Camera(materials, 0, new QVector3D(0.0f, 0.0f, -2.0f));
    clientState->addCamera(cam);
    clientState->setActiveCamera(0);

    /*
    //Text
    Font* arial = new Font(":/Fonts/Fonts/Arial/Arial.fnt", materials, 2, 1, 0.5f);
    arial->addString("What Up!", -0.5f, -0.5f);
    arial->addString("Text!", 0.5f, 0.5f);
    clientState->addText(arial);

    //Objects
    Object* obj2 = new Object(materials, 0, 0, 0, new QVector3D(1.0f, 0.0f, 0.0f));
    clientState->addObject(obj2);

    Object* obj = new Object(materials, 0, 0, 1, new QVector3D(0.0f, 0.0f, 0.0f));
    obj->setScale(new QVector3D(20.0f, 20.0f, 1.0f));
    //clientState->addObject(obj);
    */
}

void OpenGLWindow::timerEvent(QTimerEvent *)
{

    //Check for messages and update ServerState
    socketP->checkMessages();

    //Send ServerState to ClientState
    clientState->update();



    //Request an update
    update();
}

void OpenGLWindow::resizeGL(int w, int h)
{
    g_width = w;
    g_height = h;


    float width = static_cast<float>(w);
    float height = static_cast<float>(h);
    g_aspectRatio = width/height;

    //glViewport(0.0f, 0.0f, width, height);

    //set Aspect Ratio
    clientState->setWidth(width);
    clientState->setHeight(height);
    clientState->setAspectRatio(g_aspectRatio);

    //set Projection Matrix
    clientState->getProjection()->setToIdentity();
    clientState->getProjection()->perspective(90.0f, g_aspectRatio, 0.1f, 100.0f);

    //set Orthographic Matrix
    clientState->getOrthographic()->setToIdentity();
    clientState->getOrthographic()->ortho( 0.f, width, height, 0.f, -1.f, 1.f );

}

void OpenGLWindow::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Render clientState
    clientState->render(gl);

}




