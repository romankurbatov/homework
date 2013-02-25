#pragma once
#include "list.h"

struct ArrayListNode
{
    int value;
    int next;
};

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
    int maxSize;
    ArrayListNode *array;
};
