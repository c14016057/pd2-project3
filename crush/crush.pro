#-------------------------------------------------
#
# Project created by QtCreator 2015-06-08T01:45:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crush
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    square.cpp \
    rowsquare.cpp \
    colsquare.cpp \
    blocksquare.cpp \
    rainbowsquare.cpp \
    resultwindow.cpp

HEADERS  += gamewindow.h \
    square.h \
    rowsquare.h \
    colsquare.h \
    blocksquare.h \
    rainbowsquare.h \
    resultwindow.h

FORMS    += gamewindow.ui \
    resultwindow.ui

RESOURCES += \
    resource.qrc
