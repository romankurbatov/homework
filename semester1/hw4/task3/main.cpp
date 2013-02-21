#include <iostream>
#include "sortedList.h"

void printOperations()
{
    std::cout << "Возможные операции:" << std::endl;
    std::cout << "0 - выход" << std::endl;
    std::cout << "1 - добавить число в сортированный список" << std::endl;
    std::cout << "2 - удалить число из сортированного списка" << std::endl;
    std::cout << "3 - вывести список" << std::endl;
}

int getOperationNumber()
{
    std::cout << "Введите номер операции: ";
    int operationNumber = 0;
    std::cin >> operationNumber;
    return operationNumber;
}

int main()
{
    SortedList *list = createSortedList();
    bool exit = false;
    while (!exit)
    {
        printOperations();
        int operationNumber = getOperationNumber();
        switch (operationNumber)
        {
            case 0:
            {
                exit = true;
                break;
            }
            case 1:
            {
                std::cout << "Введите число для добавления в список: ";
                int value = 0;
                std::cin >> value;
                addToSortedList(list, value);
                std::cout << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Введите число для удаления из списка: ";
                int value = 0;
                std::cin >> value;
                removeFromSortedList(list, value);
                std::cout << std::endl;
                break;
            }
            case 3:
            {
                printSortedList(list);
                std::cout << std::endl;
                break;
            }
            default:
            {
                std::cout << "Некорректный номер операции!" << std::endl;
                std::cout << std::endl;
            }
        } //switch
    } //while
    deleteSortedList(list);
}

