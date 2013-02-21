void swap(int& a, int& b)
{
    if (a == b)
        return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void quickSort(int a[], int first, int last)
{
    if (first >= last)
        return;
    swap(a[first], a[(first + last) / 2]);
    int lastOfTheFirstPart = first;
    for (int i = first + 1; i <= last; i++)
        if (a[i] < a[first]) {
            lastOfTheFirstPart++;
            swap(a[i], a[lastOfTheFirstPart]);
        }
    swap(a[first], a[lastOfTheFirstPart]);
    quickSort(a, 0, lastOfTheFirstPart - 1);
    quickSort(a, lastOfTheFirstPart + 1, last);
}
