#include <iostream>
#include "quicksort.h"

void findMaxRepeatingElem(int a[], const int len, bool& found, int& value)
{
    quickSort(a, 0, len - 1);
    found = false;
    for (int i = len - 2; i >= 0; i--)
        if (a[i] == a[i + 1]) {
            found = true;
            value = a[i];
            break;
        }
}

void performTest(int a[], const int len)
{
    static int testNumber = 0;
    testNumber++;

    std::cout << "Тест " << testNumber << std::endl;
    std::cout << "Массив:" << std::endl;
    for (int i = 0; i < len; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
    int maxRep = 0;
    bool found = false;
    findMaxRepeatingElem(a, len, found, maxRep);
    if (found)
        std::cout << "Максимальный элемент, повторяющийся более одного раза: " << maxRep << std::endl;
    else
        std::cout << "Ни один элемент в массиве не повторяется дважды" << std::endl;
    std::cout << std::endl;
}

void testing()
{
    int a1[] = { 15, 8, 6, 3, 6, 7, 15, -8, 14, -8 };
    int len1 = 10;
    performTest(a1, len1);

    int a2[] = { 1, 2, 3, 4, 5 };
    int len2 = 5;
    performTest(a2, len2);
}

int main()
{
    testing();

    std::cout << "Введите длину массива: ";
    int len = 0;
    std::cin >> len;
    int *a = new int[len];
    std::cout << "Введите массив:" << std::endl;
    for (int i = 0; i < len; i++)
        std::cin >> a[i];
    bool found = false;
    int maxRep = 0;
    findMaxRepeatingElem(a, len, found, maxRep);
    if (found)
        std::cout << "Максимальный элемент, повторяющийся более одного раза: " << maxRep << std::endl;
    else
        std::cout << "Ни один элемент в массиве не повторяется дважды" << std::endl;
    delete[] a;
}

