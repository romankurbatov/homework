#pragma once

#include <QObject>
#include "calculator.h"

class Computer : public QObject
{
    Q_OBJECT
public:
    explicit Computer(Calculator *calculator, QObject *parent = 0);
    
signals:
    
public slots:
    void compute();

private:
    Calculator *calculator;
};
