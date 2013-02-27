#pragma once
#include "sorter.h"

class HeapSorter : public Sorter
{
public:
    void sort(int *array, const int size) const;
private:
    void downHeap(int *array, int k, const int n) const;
};
