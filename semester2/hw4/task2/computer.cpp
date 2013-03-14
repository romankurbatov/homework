#include "computer.h"
#include "calculator.h"
#include "ui_calculator.h"

Computer::Computer(Calculator *calculator, QObject *parent) :
    QObject(parent),
    calculator(calculator)
{
}

void Computer::compute()
{
    int argument1 = calculator->getFirstArgument();
    int argument2 = calculator->getSecondArgument();
    char operation = calculator->getOpreation();
    QString resultString;
    switch (operation)
    {
        case '+':
        {
            resultString = QString::number(argument1 + argument2);
            break;
        }
        case '-':
        {
            resultString = QString::number(argument1 - argument2);
            break;
        }
        case '*':
        {
            resultString = QString::number(argument1 * argument2);
            break;
        }
        case '/':
        {
            if (argument2 == 0)
                resultString = 'E';
            else
                resultString = QString::number(argument1 / argument2);
            break;
        }
    }
    calculator->setResult(resultString);
}
