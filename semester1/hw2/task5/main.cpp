#include <iostream>

void swap(int& a, int& b)
{
    if (a == b)
        return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void printArray(const int a[], const int len)
{
    for (int i = 0; i < len; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

void downHeap(int a[], int k, const int n)
{
    int half = n / 2;

    while (k <= half - 1) {
        int leftChild = 2*k + 1;
        int rightChild = 2*k + 2;
        int maxChild = leftChild;
        if (rightChild < n && a[rightChild] > a[leftChild])
            maxChild = rightChild;
        if (a[k] >= a[maxChild])
            break;
        swap(a[k], a[maxChild]);
        k = maxChild;
    }
}

void heapsort(int a[], const int len)
{
    for (int i = len / 2 - 1; i >= 0; i--) {
        downHeap(a, i, len);
    }
    swap(a[0], a[len - 1]);
    for (int i = 1; i < len - 1; i++) {
        downHeap(a, 0, len - i);
        swap(a[0], a[len - i - 1]);
    }
}

void performTest(int a[], const int len)
{
    static int testNumber = 0;
    testNumber++;

    std::cout << "Тест " << testNumber << std::endl;
    std::cout << "Массив до сортировки:" << std::endl;
    printArray(a, len);
    heapsort(a, len);
    std::cout << "Массив после сортировки:" << std::endl;
    printArray(a, len);
    std::cout << std::endl;
}

void testing()
{
    int a1[] = { 2, 18, 36, 5, -28, 12, 4, 0, 77, -8 };
    int len1 = 10;
    performTest(a1, len1);

    int a2[] = { 5, 4, 3, 2, 1 };
    int len2 = 5;
    performTest(a2, len2);
}

int main()
{
    testing();

    int len = 0;
    const int maxLen = 100;

    std::cout << "Введите длину массива: ";
    std::cin >> len;
    std::cout << "Введите массив для сортировки:" << std::endl;
    int a[maxLen] = {};
    for (int i = 0; i < len; i++)
        std::cin >> a[i];
    heapsort(a, len);
    std::cout << "Массив после сортировки:" << std::endl;
    printArray(a, len);
}

