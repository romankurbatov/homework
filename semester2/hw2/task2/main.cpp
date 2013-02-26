#include <iostream>
#include "stack.h"
#include "pointerStack.h"

enum StackType
{
    pointer,
    type
};

void test(StackType type)
{
    enum Operations
    {
        push = 1,
        pop = 2,
        peek = 3,
        isEmpty = 4,
        isFull = 5,
        end = 0
    };

    Stack *stack = NULL;
    stack = new PointerStack();
    while (true)
    {
        std::cout << "Тестирование стека на ";
        std::cout << "указателях" << std::endl;
        std::cout << "Возможные действия:" << std::endl;
        std::cout << push << " - вставить элемент" << std::endl;
        std::cout << pop << " - извлечь элемент" << std::endl;
        std::cout << peek << " - вывести значение головного элемента" << std::endl;
        std::cout << isEmpty << " - проверить, не пуст ли стек" << std::endl;
        std::cout << isFull << " - проверить, не заполнен ли стек" << std::endl;
        std::cout << end << " - закончить тестирование" << std::endl;
        std::cout << "Введите номер операции: ";
        int operationNumber = end;
        std::cin >> operationNumber;
        switch (operationNumber)
        {
            case push:
            {
                if (stack->isFull())
                    std::cout << "Стек заполнен!" << std::endl;
                else
                {
                    std::cout << "Введите значение: ";
                    int value = 0;
                    std::cin >> value;
                    stack->push(value);
                }
                break;
            }
            case pop:
            {
                if (stack->isEmpty())
                    std::cout << "Стек пуст!" << std::endl;
                else
                    std::cout << "Значение: " << stack->pop() << std::endl;
                break;
            }
            case peek:
            {
                if (stack->isEmpty())
                    std::cout << "Стек пуст!" << std::endl;
                else
                    std::cout << "Значение: " << stack->peek() << std::endl;
                break;
            }
            case isEmpty:
            {
                if (stack->isEmpty())
                    std::cout << "Стек пуст" << std::endl;
                else
                    std::cout << "Стек не пуст" << std::endl;
                break;
            }
            case isFull:
            {
                if (stack->isFull())
                    std::cout << "Стек заполнен" << std::endl;
                else
                    std::cout << "Стек не заполнен" << std::endl;
                break;
            }
            case end:
            {
                return;
            }
        }
    }
    delete stack;
}

int main()
{
    test(pointer);
}

