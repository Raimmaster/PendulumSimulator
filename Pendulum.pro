#-------------------------------------------------
#
# Project created by QtCreator 2015-09-13T04:04:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pendulum
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    DataInput.cpp \
    Pendulo.cpp

HEADERS  += MainWindow.h \
    DataInput.h \
    Pendulo.h

FORMS    += MainWindow.ui \
    DataInput.ui
