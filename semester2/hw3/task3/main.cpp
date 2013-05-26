#include <iostream>
#include "matrix.h"
#include "matrixTest.h"

int main()
{
    /*
    //код для интерактивного тестирования
    //потерял смысл после добавленияв модульного тестирования
    std::cout << "Введите количество строк: ";
    int numberOfRows = 0;
    std::cin >> numberOfRows;

    std::cout << "Введите количество столбцов: ";
    int numberOfColumns = 0;
    std::cin >> numberOfColumns;

    std::cout << "Создаём матрицу..." << std::endl;
    Matrix matrix(numberOfRows, numberOfColumns);

    std::cout << "Заполняем матрицу случайными числами..." << std::endl;
    matrix.fillRandom();

    std::cout << "Матрица до сортировки:" << std::endl;
    matrix.print();

    std::cout << "Сортируем столбцы матрицы..." << std::endl;
    matrix.sortColumns();

    std::cout << "Матрица после сортировки:" << std::endl;
    matrix.print();
    */
    MatrixTest test;
    QTest::qExec(&test);
}

