#pragma once
#include "list.h"

struct PointerListNode
{
    int value;
    PointerListNode *next;
};

class PointerList : public List
{
public:
    PointerList();
    ~PointerList();
    bool isInList(int value) const;
    void add(int value);
    void del(int value);
    void print() const;
private:
    PointerListNode *head;
};
