#include "arrayStack.h"

ArrayStack::ArrayStack(int size)
{
    this->size = size;
    array = new int[size];
    position = 0;
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(int value)
{
    if (position == size)
        return;
    array[position] = value;
    ++position;
}

int ArrayStack::pop()
{
    if (position == 0)
        return 0;
    --position;
    return array[position];
}

int ArrayStack::peek() const
{
    if (position == 0)
        return 0;
    return array[position - 1];
}

bool ArrayStack::isEmpty() const
{
    return (position == 0);
}

bool ArrayStack::isFull() const
{
    return (position == size);
}
