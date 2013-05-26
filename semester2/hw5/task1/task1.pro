TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hashTable.cpp \
    wordList.cpp \
    hashFunctions.cpp

HEADERS += \
    hashTable.h \
    wordList.h \
    hashFunctions.h

QMAKE_CXXFLAGS += -std=c++11
