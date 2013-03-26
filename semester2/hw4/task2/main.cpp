#include <QtGui/QApplication>
#include "calculator.h"
#include "ui_calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;

    w.show();
    
    return a.exec();
}
