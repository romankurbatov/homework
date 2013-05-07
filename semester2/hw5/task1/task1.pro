TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hashTable.cpp \
    wordList.cpp

HEADERS += \
    hashTable.h \
    wordList.h

QMAKE_CXXFLAGS += -std=c++11
