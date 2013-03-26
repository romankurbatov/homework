#pragma once

#include <QWidget>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

signals:

private slots:
    void calculate();

public slots:
    
private:
    Ui::Calculator *ui;
};
