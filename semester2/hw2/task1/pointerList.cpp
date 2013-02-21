#include <iostream>
#include "pointerList.h"
#include "pointerListNode.h"

PointerList::PointerList()
{
    head = NULL;
}

PointerList::~PointerList()
{
    if (head != NULL)
    {
        head->delList();
        delete head;
    }
}

void PointerList::add(int value)
{
    if (head == NULL)
        head = new PointerListNode(value);
    else
        head->add(value);
}

void PointerList::del(int value)
{
    if (head == NULL)
        return;
    else if (head->getValue() == value)
    {
        PointerListNode *removingNode = head;
        head = head->getNext();
        removingNode->~PointerListNode();
    }
    else
        head->del(value);
}

void PointerList::print() const
{
    if (head != NULL)
        head->print();
    else
        std::cout << std::endl;
}

bool PointerList::isInList(int value) const
{
    if (head == NULL)
        return false;
    else
        return head->isInList(value);
}
