#pragma once
#include "list.h"


class ArrayList : public List
{
public:
    ArrayList(int maxSize = 100);
    ~ArrayList();
    bool isInList(int value) const;
    void add(int value);
    void del(int value);
    void print() const;
private:
    struct ArrayListNode
    {
        int value;
        int next;
    };
    int maxSize;
    ArrayListNode *array;
};
