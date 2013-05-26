#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "sorter.h"
#include "quickSorter.h"

class QuickSorterTest : public QObject
{
    Q_OBJECT
public:
    explicit QuickSorterTest(QObject *parent = 0) : QObject(parent) {}
    
private:
    Sorter *sorter;

private slots:
    void init()
    {
        sorter = new QuickSorter;
    }

    void cleanup()
    {
        delete sorter;
    }

    void sort()
    {
        int array[] = { 1, 18, -36, 5, -110 };
        const int size = sizeof array / sizeof *array;
        sorter->sort(array, size);
        for (int i = 0; i < size - 1; ++i)
            QVERIFY(array[i] <= array[i + 1]);
    }
};
