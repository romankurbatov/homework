#include <iostream>

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
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

void printArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

void performTest(int n, int a[], int len)
{
    std::cout << "Тестовый набор " << n << std::endl;
    std::cout << "Массив до сортировки:" << std::endl;
    printArray(a, len);
    quickSort(a, 0, len - 1);
    std::cout << "Массив после сортировки:" << std::endl;
    printArray(a, len);
    std::cout << std::endl;
}

void testing()
{
    int a1[10] = { 18, 6, 12, 3, 56, 100, 78, 0, -34, 2 };
    int len1 = 10;
    performTest(1, a1, len1);

    int a2[5] = { 86, 73, 12, 7, -66 };
    int len2 = 5;
    performTest(2, a2, len2);
}

int main()
{
    testing();

    const int max = 100;
    int a[max] = {};

    std::cout << "Введите длину массива (не более " << max << "): ";
    int len = 0;
    std::cin >> len;
    std::cout << "Введите массив для сортировки:" << std::endl;
    for (int i = 0; i < len; i++)
        std::cin >> a[i];

    quickSort(a, 0, len - 1);

    std::cout << "Массив после сортировки:" << std::endl;
    printArray(a, len);
}

