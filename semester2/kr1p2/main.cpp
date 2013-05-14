#include <QCoreApplication>
#include "queue.h"
#include "queueTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QueueTest test;
    QTest::qExec(&test);

    return a.exec();
}
