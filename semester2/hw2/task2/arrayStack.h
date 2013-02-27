#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack(int size = 100);
    ~ArrayStack();
    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
private:
    int size;
    int *array;
    int position;
};
