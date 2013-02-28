#include <iostream>
#include "printer.h"
#include "consolePrinter.h"
#include "filePrinter.h"

int main()
{
    std::cout << "Введите размерность матрицы: ";
    int dimension = 0;
    std::cin >> dimension;

    int **matrix = new int*[dimension];
    for (int i = 0; i < dimension; ++i)
        matrix[i] = new int[dimension];

    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            matrix[i][j] = 0;

    std::cout << "Введите матрицу:" << std::endl;
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            std::cin >> matrix[i][j];

    enum Modes
    {
        console = 1,
        file = 2
    };

    Printer *printer = NULL;

    std::cout << "Режимы вывода:" << std::endl;
    std::cout << console << " - на консоль" << std::endl;
    std::cout << file << " - в файл"  << std::endl;
    std::cout << "Введите номер режима: ";
    int modeNumber = console;
    std::cin >> modeNumber;
    if (modeNumber == console)
        printer = new ConsolePrinter;
    else
        printer = new FilePrinter("output.txt");

    printer->print(matrix, dimension);

    delete printer;

    for (int i = 0; i < dimension; ++i)
        delete[] matrix[i];
    delete matrix;
}

