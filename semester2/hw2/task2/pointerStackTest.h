#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "stack.h"
#include "pointerStack.h"

class PointerStackTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerStackTest(QObject *parent = 0) : QObject(parent) {}
    
private:
    Stack *stack;

private slots:
    void init()
    {
        stack = new PointerStack;
    }

    void cleanup()
    {
        delete stack;
    }

    void empty()
    {
        QVERIFY(stack->isEmpty());
        QVERIFY(!stack->isFull());
    }

    void pushOne()
    {
        int value = 5;
        stack->push(value);
        QVERIFY(stack->peek() == value);
        QVERIFY(!stack->isEmpty());
        QVERIFY(stack->pop() == value);
        QVERIFY(stack->isEmpty());
    }

    void pushTwo()
    {
        int firstValue = 5;
        int secondValue = 10;
        stack->push(firstValue);
        stack->push(secondValue);
        QVERIFY(!stack->isEmpty());
        QVERIFY(stack->peek() == secondValue);
        QVERIFY(stack->pop() == secondValue);
        QVERIFY(!stack->isEmpty());
        QVERIFY(stack->peek() == firstValue);
        QVERIFY(stack->pop() == firstValue);
        QVERIFY(stack->isEmpty());
    }
};
