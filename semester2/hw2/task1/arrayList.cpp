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
    for (int i = 0; i < maxSize - 1; ++i)
    {
        array[i + 2].next = i + 3;
        array[i + 2].value = 0;
    }
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
    while (next != 0 && array[next].value != value)
    {
        current = next;
        next = array[current].next;
    }
    if (next == 0)
        return;
    int removing = next;
    array[current].next = array[removing].next;
    array[removing].next = array[1].next;
    array[1].next = removing;
}

void ArrayList::print() const
{
    int current = array[0].next;
    while (current != 0)
    {
        std::cout << array[current].value << ' ';
        current = array[current].next;
    }
    std::cout << '\n';
}
