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
    cfg.cpp \
    core/app.cpp \
    core/screen.cpp \
    core/widget.cpp \
    gfx_engine/gfxengine.cpp \
    gfx_engine/resourceloader.cpp \
    life/life.cpp \
    life/lifeinfo.cpp \
    life/lifescreen.cpp \
    gfx_engine/resourcecontainer.cpp \
    pong/pongscreen.cpp \
    pong/pong.cpp \
    fpscounter.cpp \
    gfx_engine/text.cpp \
    pong/ponginfo.cpp \
    pong/pongwinwidget.cpp

HEADERS += \
    cfg.h \
    core/app.h \
    core/screen.h \
    core/widget.h \
    gfx_engine/gfxengine.h \
    gfx_engine/resourcecontainer.h \
    gfx_engine/resourceloader.h \
    life/life.h \
    life/lifeinfo.h \
    life/lifescreen.h \
    gfx_engine/resourcecontainer.h \
    pong/pongscreen.h \
    pong/pong.h \
    fpscounter.h \
    gfx_engine/text.h \
    pong/ponginfo.h \
    pong/pongwinwidget.h
