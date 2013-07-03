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
    firstbarrier.cpp \
    secondbarrier.cpp \
    thirdbarrier.cpp \
    enemy.cpp \
    firstfire.cpp \
    fire.cpp \
    firstenemy.cpp \
    headmenu.cpp \
    mainmenu.cpp \
    menu.cpp

HEADERS  += \
    gamewidget.h \
    myConsts.h \
    mario.h \
    barriers.h \
    firstbarrier.h \
    secondbarrier.h \
    thirdbarrier.h \
    enemy.h \
    firstfire.h \
    fire.h \
    firstenemy.h \
    headmenu.h \
    mainmenu.h \
    menu.h

RESOURCES += \
    Resourses.qrc
