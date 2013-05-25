#include <iostream>
#include <cstdio>
#include "stack.h"
#include "pointerStack.h"
#include "arrayStack.h"
#include "pointerStackTest.h"
#include "arrayStackTest.h"

/*
//код для интерактивного тестирования
//потерял смысл после введения модульного тестирования
enum StackType
{
    pointer = 1,
    array = 2
};

bool getOperands(Stack *stack, double &operand1, double &operand2)
{
    if (stack->isEmpty())
    {
        std::cout << "Ошибка в выражении" << std::endl;
        return false;
    }
    operand2 = stack->pop();
    if (stack->isEmpty())
    {
        std::cout << "Ошибка в выражении" << std::endl;
        return false;
    }
    operand1 = stack->pop();
    return true;
}
*/

int main()
{
    /*
    //код для интерактивного тестирования
    std::cout << "Какой стек вы хотите использовать?" << std::endl;
    std::cout << pointer << " - на указателях" << std::endl;
    std::cout << array << " - на массиве" << std::endl;
    std::cout << "Введите номер: ";
    int type = pointer;
    std::cin >> type;
    char c = std::cin.get();
    while (c != '\n')
        c = std::cin.get();
    Stack *stack = NULL;
    if (type == pointer)
        stack = new PointerStack;
    else
        stack = new ArrayStack;
    std::cout << "Введите выражение: ";
    while (true)
    {
        c = std::cin.get();
        switch (c)
        {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9': case '0':
            {
                if (stack->isFull())
                {
                    std::cout << "Переполнение стека" << std::endl;
                    delete stack;
                    return 0;
                }
                stack->push(c - '0');
                break;
            }
            case '+':
            {
                double operand1 = 0;
                double operand2 = 0;
                if (!getOperands(stack, operand1, operand2))
                {
                    delete stack;
                    return 0;
                }
                double result = operand1 + operand2;
                stack->push(result);
                break;
            }
            case '-':
            {
                double operand1 = 0;
                double operand2 = 0;
                if (!getOperands(stack, operand1, operand2))
                {
                    delete stack;
                    return 0;
                }
                double result = operand1 - operand2;
                stack->push(result);
                break;
            }
            case '*':
            {
                double operand1 = 0;
                double operand2 = 0;
                if (!getOperands(stack, operand1, operand2))
                {
                    delete stack;
                    return 0;
                }
                double result = operand1 * operand2;
                stack->push(result);
                break;
            }
            case '/':
            {
                double operand1 = 0;
                double operand2 = 0;
                if (!getOperands(stack, operand1, operand2))
                {
                    delete stack;
                    return 0;
                }
                if (operand2 == 0)
                {
                    std::cout << "Деление на ноль" << std::endl;
                    delete stack;
                    return 0;
                }
                double result = operand1 / operand2;
                stack->push(result);
                break;
            }
            case '\n': case EOF:
            {
                if (stack->isEmpty())
                    std::cout << "Ошибка в выражении" << std::endl;
                else
                    std::cout << "Результат: " << stack->pop() << std::endl;
                delete stack;
                return 0;
            }
            default:
            {
                std::cout << "Некорректный симовол" << std::endl;
                delete stack;
                return 0;
            }
        }
    }
    */

    PointerStackTest pointerTest;
    QTest::qExec(&pointerTest);

    ArrayStackTest arrayTest;
    QTest::qExec(&arrayTest);
}

