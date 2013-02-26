#pragma once

class Stack
{
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};
