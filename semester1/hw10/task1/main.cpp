#include <iostream>
#include <polynomial.h>

const int memorySize = 100;
int occupiedCells = 0;
Polynomial *memory[memorySize];

int getCellNumber()
{
    int cell = 0;
    std::cin >> cell;
    if (cell < 0)
        std::cout << "Некорректный номер ячейки" << std::endl;
    else if (cell >= occupiedCells)
        std::cout << "Эта ячейка свободна!" << std::endl;
    else
        return cell;
    return -1;
}

int main()
{
    enum Commands
    {
        addToMemory = 1,
        getFromMemory = 2,
        checkEquality = 3,
        countValue = 4,
        countSum = 5,
        exit = 6
    };


    for (int i = 0; i < memorySize; ++i)
        memory[i] = nullptr;

    while (true)
    {
        std::cout << "Возможные действия:" << std::endl;
        std::cout << "1 - добавить многочлен в память" << std::endl;
        std::cout << "2 - вывести многочлен, хранящийся в памяти" << std::endl;
        std::cout << "3 - проверить равенство многочленов" << std::endl;
        std::cout << "4 - вычислить значение многочлена в точке" << std::endl;
        std::cout << "5 - вычислить сумму многочленов" << std::endl;
        std::cout << "6 - выйти" << std::endl;
        std::cout << "Введите номер команды: ";
        int command = 0;
        std::cin >> command;
        switch (command)
        {
            case addToMemory:
            {
                if (occupiedCells == memorySize)
                {
                    std::cout << "Нет свободной памяти!" << std::endl;
                    break;
                }
                Polynomial *p = getPolynomial();
                printPolynomial(p);
                memory[occupiedCells] = p;
                std::cout << "Многочлен записан в ячейку памяти " << occupiedCells << std::endl;
                ++occupiedCells;
                break;
            }
            case getFromMemory:
            {
                std::cout << "Введите номер ячейки: ";
                int cell = getCellNumber();
                if (cell != -1)
                    printPolynomial(memory[cell]);
                break;
            }
            case checkEquality:
            {
                std::cout << "Введите номера ячеек памяти: ";
                int cell1 = getCellNumber();
                if (cell1 == -1)
                    break;
                int cell2 = getCellNumber();
                if (cell2 == -1)
                    break;
                Polynomial *p = memory[cell1];
                printPolynomial(p);
                Polynomial *q = memory[cell2];
                printPolynomial(q);
                if (equals(p, q))
                    std::cout << "Многочлены равны" << std::endl;
                else
                    std::cout << "Многочлены не равны" << std::endl;
                break;
            }
            case countValue:
            {
                std::cout << "Введите номер ячейки: ";
                int cell = getCellNumber();
                if (cell == -1)
                    break;
                Polynomial *p = memory[cell];
                printPolynomial(p);
                std::cout << "Введите точку: ";
                double x = 0;
                std::cin >> x;
                double result = value(p, x);
                std::cout << "Результат: " << result << std::endl;
                break;
            }
            case countSum:
            {
                std::cout << "Введите номера ячеек памяти: ";
                int cell1 = getCellNumber();
                if (cell1 == -1)
                    break;
                int cell2 = getCellNumber();
                if (cell2 == -1)
                    break;
                Polynomial *p = memory[cell1];
                printPolynomial(p);
                Polynomial *q = memory[cell2];
                printPolynomial(q);
                Polynomial *r = createPolynomial();
                add(p, q, r);
                std::cout << "Сумма многочленов:" << std::endl;
                printPolynomial(r);
                if (occupiedCells < memorySize)
                {
                    memory[occupiedCells] = r;
                    std::cout << "Сумма записана в ячейку памяти " << occupiedCells << std::endl;
                    ++occupiedCells;
                }
                else
                    deletePolynomial(r);
                break;
            }
            case exit:
            {
                for (int i = 0; i < occupiedCells; ++i)
                    deletePolynomial(memory[i]);
                return 0;
            }
            default:
            {
                std::cout << "Неверный номер команды" << std::endl;
                break;
            }
        }
    }
}

