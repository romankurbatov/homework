#include <iostream>
#include "pointerListNode.h"

PointerListNode::PointerListNode(int value)
{
    this->value = value;
}

void PointerListNode::add(int value)
{
    if (this->value == value)
        return;
    else if (next == NULL)
        next = new PointerListNode(value);
    else
        next->add(value);
}

void PointerListNode::del(int value)
{
    if (next == NULL)
        return;
    else if (next->getValue() == value)
    {
        PointerListNode *removingNode = next;
        next = next->getNext();
        delete removingNode;
    }
    else
        next->del(value);
}

int PointerListNode::getValue() const
{
    return value;
}

PointerListNode *PointerListNode::getNext() const
{
    return next;
}

void PointerListNode::print() const
{
    std::cout << value << ' ';
    if (next != NULL)
        next->print();
    else
        std::cout << std::endl;
}

bool PointerListNode::isInList(int value) const
{
    if (this->value == value)
        return true;
    else if (next == NULL)
        return false;
    else
        return next->isInList(value);
}

void PointerListNode::delList()
{
    if (next != NULL)
    {
        next->delList();
        delete next;
    }
}
