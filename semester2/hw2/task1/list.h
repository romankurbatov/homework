#pragma once

class List
{
public:
    virtual bool isInList(int value) const = 0;
    virtual void add(int value) = 0;
    virtual void del(int value) = 0;
    virtual void print() const = 0;
};