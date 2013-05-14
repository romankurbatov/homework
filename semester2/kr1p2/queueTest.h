#pragma once

#include <QtCore/QObject>
#include <QObject>
#include <QtTest/QTest>
#include "queue.h"

class QueueTest : public QObject
{
    Q_OBJECT
public:
    explicit QueueTest(QObject *parent = 0) {}
    
signals:
    
public slots:
    void testQueue1()
    {
        Queue<int> queue;
        queue.enqueue(1, 1);
        queue.enqueue(2, 0);
        QVERIFY(queue.dequeue() == 1);
        QVERIFY(queue.dequeue() == 2);
    }
    
};
