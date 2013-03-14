#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    QObject::connect(this->ui->firstArgument, SIGNAL(valueChanged(int)), this, SLOT(emitSomethingChanged()));
    QObject::connect(this->ui->secondArgument, SIGNAL(valueChanged(int)), this, SLOT(emitSomethingChanged()));
    QObject::connect(this->ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(emitSomethingChanged()));
}

Calculator::~Calculator()
{
    delete ui;
}

int Calculator::getFirstArgument() const
{
    return ui->firstArgument->value();
}

int Calculator::getSecondArgument() const
{
    return ui->secondArgument->value();
}

char Calculator::getOpreation() const
{
    return ui->operation->currentText()[0].toAscii();
}

void Calculator::setResult(const QString &result)
{
    this->ui->result->setText(result);
}

void Calculator::emitSomethingChanged()
{
    emit somethingChanged();
}
