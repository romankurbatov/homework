#pragma once

class Stack
{
public:
    virtual ~Stack()
    {

    }

    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual int peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};
