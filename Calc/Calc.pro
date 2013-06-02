#-------------------------------------------------
#
# Project created by QtCreator 2013-05-29T15:04:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculateexpression.cpp \
    parser.cpp \
    lexer.cpp

HEADERS  += mainwindow.h \
    calculateexpression.h \
    parser.h \
    lexer.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    ../../../../../../Documents and Settings/Irina/Рабочий стол/Универ/Программирование/Губанов/Grammar2/Grammar/CalculateParserResult.cs \
    CalculateParserResult.cs
