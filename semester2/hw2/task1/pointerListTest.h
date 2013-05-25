#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "list.h"
#include "pointerList.h"
#include "arrayList.h"

class PointerListTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerListTest(QObject *parent = 0) : QObject(parent) {}
    
private:
    List *list;

private slots:
    void init()
    {
        list = new PointerList;
    }

    void cleanup()
    {
        delete list;
    }

    void empty()
    {
        QVERIFY(!list->isInList(15));
    }

    void addOne()
    {
        list->add(5);
        QVERIFY(list->isInList(5));
        QVERIFY(!list->isInList(10));
        list->del(5);
        QVERIFY(!list->isInList(5));
    }

    void addTwo()
    {
        list->add(5);
        list->add(10);
        QVERIFY(list->isInList(5));
        QVERIFY(list->isInList(10));
        QVERIFY(!list->isInList(15));
        list->del(5);
        QVERIFY(!list->isInList(5));
        QVERIFY(list->isInList(10));
        list->del(10);
        QVERIFY(!list->isInList(10));
        QVERIFY(!list->isInList(5));
    }
};
