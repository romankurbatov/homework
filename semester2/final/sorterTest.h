#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "sorter.h"
#include "comparer.h"

class sorterTest : public QObject
{
    Q_OBJECT
public:
    explicit sorterTest(QObject * = 0) {}

private:
    static int compareInt(const int &a, const int &b)
    {
        return a - b;
    }

signals:
    
private slots:
    void testInt()
    {
        Comparer<int> intComparer(&compareInt);
        Sorter<int> intSorter;
        int array[] = { 5, 18, -2, 33, 0};
        int size = sizeof array / sizeof *array;
        intSorter.bubbleSort(array, size, intComparer);
        for (int i = 0; i < size - 1; ++i)
            QVERIFY(array[i] < array[i + 1]);
    }
};
