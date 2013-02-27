#pragma once
#include "stack.h"

struct PointerStackElement
{
    double value;
    PointerStackElement *next;
};

class PointerStack : public Stack
{
public:
    PointerStack();
    ~PointerStack();
    void push(double value);
    double pop();
    double peek() const;
    bool isEmpty() const;
    bool isFull() const;
private:
    PointerStackElement *top;
};
