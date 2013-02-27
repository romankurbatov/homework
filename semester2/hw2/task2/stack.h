#pragma once

class Stack
{
public:
    virtual ~Stack()
    {

    }

    virtual void push(double value) = 0;
    virtual double pop() = 0;
    virtual double peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};
