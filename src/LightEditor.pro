#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T22:09:47
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LightEditor
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    glwidget.cpp \
    mesh.cpp \
    plyreader.cpp \
    meshreader.cpp \
    testreader.cpp \
    process_mesh.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    mesh.h \
    plyreader.h \
    meshreader.h \
    testreader.h \
    process_mesh.h

FORMS    += mainwindow.ui

DISTFILES += \
    simple-frag.glsl \
    simple-vert.glsl

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ply/build/ -lply
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ply/build/ -lplyd
else:unix: LIBS += -L$$PWD/ply/build/ -lply

INCLUDEPATH += $$PWD/ply
DEPENDPATH += $$PWD/ply
