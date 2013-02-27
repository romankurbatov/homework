#include "selectionSorter.h"
#include "swap.h"

void SelectionSorter::sort(int *array, const int size) const
{
    for (int i = 0; i < size; ++i)
    {
        int min = i;
        for (int j = i + 1; j < size; ++j)
            if (array[j] < array[min])
                min = j;
        swap(array[i], array[min]);
    }
}
