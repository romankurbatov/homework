#pragma once
#include "stack.h"

struct PointerStackElement
{
    int value;
    PointerStackElement *next;
};

class PointerStack : public Stack
{
public:
    PointerStack();
    ~PointerStack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty() const;
    bool isFull() const;
private:
    PointerStackElement *top;
};
