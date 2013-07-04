#-------------------------------------------------
#
# Project created by QtCreator 2013-06-18T13:55:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mario
TEMPLATE = app


SOURCES += main.cpp \
    gamewidget.cpp \
    mario.cpp \
    barriers.cpp \
    enemy.cpp \
    fire.cpp \
    headmenu.cpp \
    mainmenu.cpp

HEADERS  += \
    gamewidget.h \
    myConsts.h \
    mario.h \
    barriers.h \
    enemy.h \
    fire.h \
    headmenu.h \
    mainmenu.h

RESOURCES += \
    Resourses.qrc
