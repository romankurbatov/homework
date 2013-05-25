#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "list.h"
#include "pointerList.h"
#include "arrayList.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}
    
private slots:
    void test()
    {
        List *list = NULL;
        for (int i = 0; i <= 1; ++i)
        {
            if (i == 0)
                list = new PointerList;
            else
                list = new ArrayList;
            int firstValue = 5;
            int secondValue = 10;
            int anotherValue = 15;
            QVERIFY(!list->isInList(firstValue));
            list->add(firstValue);
            QVERIFY(list->isInList(firstValue) &&!list->isInList(secondValue));
            list->add(secondValue);
            QVERIFY(list->isInList(firstValue) && list->isInList(secondValue) &&
                    !list->isInList(anotherValue));
            list->del(firstValue);
            QVERIFY(list->isInList(secondValue) && !list->isInList(firstValue));
            list->del(secondValue);
            QVERIFY(!list->isInList(firstValue) && !list->isInList(secondValue));
            delete list;
        }
    }
};
