#-------------------------------------------------
#
# Project created by QtCreator 2017-10-30T19:24:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mouse
TEMPLATE = app

CONFIG +=c++14

SOURCES += main.cpp\
        widget.cpp \
    spider.cpp

HEADERS  += widget.h \
    spider.h

FORMS    += widget.ui
