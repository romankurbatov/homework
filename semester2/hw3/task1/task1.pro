TEMPLATE = app
CONFIG += console
CONFIG -= qt

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
    heapSorter.h

