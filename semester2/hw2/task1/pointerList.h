#pragma once
#include "list.h"
#include "pointerListNode.h"

class PointerList : public List
{
public:
    PointerList();
    ~PointerList();
    void add(int value);
    void del(int value);
    void print() const;
    bool isInList(int value) const;
private:
    PointerListNode *head;
};
