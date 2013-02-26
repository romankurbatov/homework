#include <iostream>
#include "pointerList.h"

PointerList::PointerList()
{
    head = NULL;
}

PointerList::~PointerList()
{
    if (head == NULL)
        return;
    PointerListNode *currentNode = head;
    while (currentNode != NULL)
    {
        PointerListNode *removingNode = currentNode;
        currentNode = currentNode->next;
        delete removingNode;
    }
}

bool PointerList::isInList(int value) const
{
    PointerListNode *currentNode = head;
    while (currentNode != NULL)
    {
        if (currentNode->value == value)
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

void PointerList::add(int value)
{
    if (isInList(value))
        return;
    PointerListNode *newNode = new PointerListNode;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void PointerList::del(int value)
{
    if (head == NULL)
        return;
    if (head->value == value)
    {
        PointerListNode *removingNode = head;
        head = head->next->next;
        delete removingNode;
        return;
    }
    PointerListNode *currentNode = head;
    PointerListNode *nextNode = head->next;
    while (nextNode != NULL)
    {
        if (nextNode->value == value)
        {
            currentNode->next = nextNode->next;
            delete nextNode;
            return;
        }
        currentNode = nextNode;
        nextNode = currentNode->next;
    }
}

void PointerList::print() const
{
    PointerListNode *currentNode = head;
    while (currentNode != NULL)
    {
        std::cout << currentNode->value << ' ';
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}
