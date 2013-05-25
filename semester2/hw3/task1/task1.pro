TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

QT += testlib

SOURCES += main.cpp \
    selectionSorter.cpp \
    quickSorter.cpp \
    swap.cpp \
    heapSorter.cpp

HEADERS += \
    sorter.h \
    selectionSorter.h \
    quickSorter.h \
    swap.h \
    heapSorter.h \
    heapSorterTest.h \
    quickSorterTest.h \
    selectionSorterTest.h

