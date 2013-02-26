#include "arrayList.h"
#include <iostream>

ArrayList::ArrayList(int maxSize)
{
    this->maxSize = maxSize;
    array = new ArrayListNode[maxSize + 2];
    array[0].next = 0;
    array[0].value = 0;
    array[1].next = 2;
    array[1].value = 0;
    for (int i = 2; i <= maxSize; ++i)
        array[i].next = i + 1;
    array[maxSize + 1].next = 1;
    array[maxSize + 1].value = 0;
}

ArrayList::~ArrayList()
{
    delete[] array;
}

bool ArrayList::isInList(int value) const
{
    int current = array[0].next;
    while (current != 0)
    {
        if (array[current].value == value)
            return true;
        current = array[current].next;
    }
    return false;
}

void ArrayList::add(int value)
{
    if (isInList(value)) //уже есть в списке
        return;
    if (array[1].next == 1) //список заполнен
        return;
    int newNode = array[1].next;
    array[1].next = array[array[1].next].next;
    array[newNode].value = value;
    array[newNode].next = array[0].next;
    array[0].next = newNode;
}

void ArrayList::del(int value)
{
    int current = 0;
    int next = array[current].next;
    while (next != 0)
    {
        if (array[next].value == value)
        {
            array[current].next = array[next].next;
            array[next].next = array[1].next;
            array[1].next = next;
            return;
        }
        current = next;
        next = array[current].next;
    }
}

void ArrayList::print() const
{
    int current = array[0].next;
    while (current != 0)
    {
        std::cout << array[current].value << ' ';
        current = array[current].next;
    }
    std::cout << std::endl;
}
