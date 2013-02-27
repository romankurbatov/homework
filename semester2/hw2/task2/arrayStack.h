#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack(int size = 100);
    ~ArrayStack();
    void push(double value);
    double pop();
    double peek() const;
    bool isEmpty() const;
    bool isFull() const;
private:
    int size;
    double *array;
    int position;
};
