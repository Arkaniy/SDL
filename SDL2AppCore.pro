#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T20:12:41
#
#-------------------------------------------------

QT       += core

QT       -= gui

QMAKE_CXXFLAGS += -std=c++14
LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf

TARGET = SDL2AppCore
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    app.cpp \
    gui/widget.cpp \
    gfxengine.cpp \
    life.cpp \
    resourceloader.cpp \
    imagecontainer.cpp \
    cfg.cpp \
    lifeinfo.cpp

HEADERS += \
    app.h \
    gui/widget.h \
    gfxengine.h \
    life.h \
    resourceloader.h \
    imagecontainer.h \
    cfg.h \
    lifeinfo.h
