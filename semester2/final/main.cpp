#include <QCoreApplication>
#include "sorterTest.h"

int compareInt(const int &a, const int &b)
{
    return a - b;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    sorterTest test;
    QTest::qExec(&test);

    return a.exec();
}
