#include "pointerStack.h"
#include <cstdlib>

PointerStack::PointerStack()
{
    top = NULL;
}

PointerStack::~PointerStack()
{
    PointerStackElement *currentElement = top;
    while (currentElement != NULL)
    {
        PointerStackElement *removingElement = currentElement;
        currentElement = currentElement->next;
        delete removingElement;
    }
}

void PointerStack::push(int value)
{
    PointerStackElement *newElement = new PointerStackElement;
    newElement->value = value;
    newElement->next = top;
    top = newElement;
}

int PointerStack::pop()
{
    if (top == NULL)
        return 0;
    int value = top->value;
    PointerStackElement *removingElement = top;
    top = top->next;
    delete removingElement;
    return value;
}

int PointerStack::peek()
{
    if (top == NULL)
        return 0;
    return top->value;
}

bool PointerStack::isEmpty() const
{
    return (top == NULL);
}

bool PointerStack::isFull() const
{
    return false;
}
