#include <iostream>
#include "sorter.h"
#include "selectionSorter.h"
#include "quickSorter.h"
#include "heapSorter.h"

int main()
{
    enum Algorithms
    {
        selection = 1,
        quick = 2,
        heap = 3
    };

    std::cout << "Введите количество элементов в массиве: ";
    int size = 0;
    std::cin >> size;

    int *array = new int[size];
    std::cout << "Введите массив: ";
    for (int i = 0; i < size; ++i)
        std::cin >> array[i];

    std::cout << "Алгоритмы сортировки:" << std::endl;
    std::cout << selection << " - сортировка выбором" << std::endl;
    std::cout << quick << " - быстрая сортировка" << std::endl;
    std::cout << heap << " - пирамидальная сортировка" << std::endl;
    std::cout << "Введите номер алгоритма: ";
    int algorithm = selection;
    std::cin >> algorithm;

    Sorter *sorter = NULL;
    if (algorithm == selection)
        sorter = new SelectionSorter;
    else if (algorithm == quick)
        sorter = new QuickSorter;
    else
        sorter = new HeapSorter;
    sorter->sort(array, size);

    std::cout << "Массив после сортировки: ";
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
    delete sorter;
    delete[] array;
}

