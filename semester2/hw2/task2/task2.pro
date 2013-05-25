TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

QT += testlib

SOURCES += main.cpp \
    pointerStack.cpp \
    arrayStack.cpp

HEADERS += \
    stack.h \
    pointerStack.h \
    arrayStack.h \
    pointerStackTest.h \
    arrayStackTest.h

