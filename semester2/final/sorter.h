#pragma once
#include "comparer.h"

template<typename T>
class Sorter
{
public:
    Sorter() {}
    void bubbleSort(T *array, int size, Comparer<T> comparer);
private:
    void swap(T &a, T &b);
};

template<typename T>
void Sorter<T>::bubbleSort(T *array, int size, Comparer<T> comparer)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < size - 1; ++i)
            if (comparer.compare(array[i], array[i + 1]) > 0)
            {
                sorted = false;
                swap(array[i], array[i + 1]);
            }
    }
}

template<typename T>
void Sorter<T>::swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}
