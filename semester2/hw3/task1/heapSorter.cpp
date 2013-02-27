#include "heapSorter.h"
#include "swap.h"

void HeapSorter::downHeap(int *array, int k, const int n) const
{
    int half = n / 2;

    while (k <= half - 1)
    {
        int leftChild = 2*k + 1;
        int rightChild = 2*k + 2;
        int maxChild = leftChild;
        if (rightChild < n && array[rightChild] > array[leftChild])
            maxChild = rightChild;
        if (array[k] >= array[maxChild])
            break;
        swap(array[k], array[maxChild]);
        k = maxChild;
    }
}

void HeapSorter::sort(int *array, const int size) const
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        downHeap(array, i, size);
    }
    swap(array[0], array[size - 1]);
    for (int i = 1; i < size - 1; ++i)
    {
        downHeap(array, 0, size - i);
        swap(array[0], array[size - i - 1]);
    }
}

