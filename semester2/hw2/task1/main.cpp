#include <iostream>
#include "list.h"
#include "pointerList.h"

int main()
{
    enum Operations
    {
        add = 1,
        del = 2,
        print = 3,
        check = 4,
        end = 0
    };

    bool finished = false;
    List *list = new PointerList();
    while (!finished)
    {
        std::cout << "Тестирование связного списка на указателях" << std::endl;
        std::cout << "Возможные операции:" << std::endl;
        std::cout << add << " - добавить элемент" << std::endl;
        std::cout << del << " - удалить элемент" << std::endl;
        std::cout << print << " - вывести список" << std::endl;
        std::cout << check << " - проверить наличие элемента" << std::endl;
        std::cout << end << " - закончить тестирование" << std::endl;
        int operationNumber = end;
        std::cout << "Введите номер оперции: ";
        std::cin >> operationNumber;
        switch (operationNumber)
        {
            case add:
            {
                std::cout << "Добавление элемента" << std::endl;
                int value = 0;
                std::cout << "Введите значение: ";
                std::cin >> value;
                list->add(value);
                break;
            }
            case del:
            {
                std::cout << "Удаление элемента" << std::endl;
                int value = 0;
                std::cout << "Введите значение: ";
                std::cin >> value;
                list->del(value);
                break;
            }
            case print:
            {
                std::cout << "Вывод списка: ";
                list->print();
                break;
            }
            case check:
            {
                std::cout << "Проверка наличия элемента" << std::endl;
                int value = 0;
                std::cout << "Введите значение: ";
                std::cin >> value;
                if (list->isInList(value))
                    std::cout << "Элемент есть в списке" << std::endl;
                else
                    std::cout << "Элемента нет в списке" << std::endl;
                break;
            }
            case end:
            {
                finished = true;
                break;
            }
            default:
            {
                std::cout << "Некорректный номер операции" << std::endl;
                break;
            }
        }
    }
}

