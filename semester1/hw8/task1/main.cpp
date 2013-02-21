#include <iostream>

void swap(int& a, int& b)
{
    if (a == b)
        return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void bubbleSort(int array[], int length)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < length - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                sorted = false;
                swap(array[i], array[i + 1]);
            }
        }
    }
}

int main()
{
    std::cout << "Введите длину массива: ";
    int length = 0;
    std::cin >> length;
    int *array = new int[length];
    std::cout << "Введите массив: ";
    for (int i = 0; i < length; ++i)
        std::cin >> array[i];
    bubbleSort(array, length);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < length; ++i)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
    delete[] array;
}

