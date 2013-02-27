#include "quickSorter.h"
#include "swap.h"

void QuickSorter::quickSort(int *array, const int first, const int last) const
{
    if (first >= last)
        return;
    swap(array[first], array[(first + last) / 2]);
    int lastOfTheFirstPart = first;
    for (int i = first + 1; i <= last; i++)
        if (array[i] < array[first]) {
            ++lastOfTheFirstPart;
            swap(array[i], array[lastOfTheFirstPart]);
        }
    swap(array[first], array[lastOfTheFirstPart]);
    quickSort(array, 0, lastOfTheFirstPart - 1);
    quickSort(array, lastOfTheFirstPart + 1, last);
}

void QuickSorter::sort(int *array, const int size) const
{
    quickSort(array, 0, size - 1);
}
