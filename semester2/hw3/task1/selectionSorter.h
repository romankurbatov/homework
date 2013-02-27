#pragma once
#include "sorter.h"

class SelectionSorter : public Sorter
{
public:
    void sort(int *array, const int size) const;
};
