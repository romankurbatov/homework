#pragma once

class PointerListNode
{
public:
    PointerListNode(int value);
    void add(int value);
    void del(int value);
    int getValue() const;
    PointerListNode *getNext() const;
    void print() const;
    bool isInList(int value) const;
    void delList();
private:
    int value;
    PointerListNode *next;
};
