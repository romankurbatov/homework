#include <iostream>
#include "circularList.h"

int main()
{
    std::cout << "Введите количество элементов в исходном списке: ";
    int numberOfItems = 0;
    std::cin >> numberOfItems;

    std::cout << "Какой элемент должен остаться последним? ";
    int i = 0;
    std::cin >> i;

    std::cout << "Этот элемент останется последним, если удалять элемент с номером: ";
    for (int k = 1; k <= numberOfItems; k++)
    {
        CircularList *list = createCircularList(numberOfItems);
        if (count(list, k) == i)
            std::cout << k << ' ';
    }
    std::cout << std::endl;
}

