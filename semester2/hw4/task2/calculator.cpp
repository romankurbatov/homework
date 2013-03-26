#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    setFixedSize(size());
    QObject::connect(ui->firstArgument, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    QObject::connect(ui->secondArgument, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    QObject::connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(calculate()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::calculate()
{
    int argument1 = ui->firstArgument->value();
    int argument2 = ui->secondArgument->value();
    char operation = ui->operation->currentText()[0].toAscii();
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
    ui->result->setText(resultString);
}
