#include <QtGui/QApplication>
#include "calculator.h"
#include "ui_calculator.h"
#include "computer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    Computer computer(&w);

    QObject::connect(&w, SIGNAL(somethingChanged()), &computer, SLOT(compute()));

    w.show();
    
    return a.exec();
}
