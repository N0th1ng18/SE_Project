#-------------------------------------------------
#
# Project created by QtCreator 2019-04-03T21:27:28
#
#-------------------------------------------------

QT  += core gui
QT  += network
QT  += quick
QT  += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SE_Project
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    openglwindow.cpp \
    model.cpp \
    clientprotocol.cpp \
    playerinfo.cpp \
    shader.cpp \
    queryhandler.cpp \
    texture.cpp \
    vao.cpp \
    vbo.cpp \
    materials.cpp \
    clientstate.cpp \
    object.cpp \
    text.cpp
    gamerenderer.cpp

HEADERS += \
    openglwindow.h \
    clientprotocol.h \
    playerinfo.h \
    queryhandler.h \
    model.h \
    shader.h \
    texture.h \
    vao.h \
    vbo.h \
    materials.h \
    clientstate.h \
    object.h \
    text.h \
    gamerenderer.h

FORMS +=

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    shaders.qrc \
    textures.qrc \
    qml.qrc

