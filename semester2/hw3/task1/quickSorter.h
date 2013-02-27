#pragma once
#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    void sort(int *array, const int size) const;
private:
    void quickSort(int *array, const int first, const int last) const;
};
