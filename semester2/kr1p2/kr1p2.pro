#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T13:48:00
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = kr1p2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += qtestlib

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    queue.h \
    queueTest.h

QMAKE_CXXFLAGS += -std=c++11
