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
    int getFirstArgument() const;
    int getSecondArgument() const;
    char getOpreation() const;
    void setResult(const QString &result);

signals:
    void somethingChanged();

public slots:
    void emitSomethingChanged();
    
private:
    Ui::Calculator *ui;
};
