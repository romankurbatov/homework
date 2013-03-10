#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

Matrix::Matrix(int numberOfRows, int numberOfColumns)
    : numberOfRows(numberOfRows), numberOfColumns(numberOfColumns)
{
    matrix = new int*[numberOfColumns];
    for (int i = 0; i < numberOfColumns; ++i)
    {
        matrix[i] = new int[numberOfRows];
        for (int j = 0; j < numberOfRows; ++j)
            matrix[i][j] = 0;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < numberOfColumns; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void Matrix::fillRandom()
{
    srand(time(NULL));
    for (int i = 0; i < numberOfColumns; ++i)
        for (int j = 0; j < numberOfRows; ++j)
            matrix[i][j] = rand() % (maxRandomElement + 1);
}

void Matrix::print() const
{
    for (int i = 0; i < numberOfRows; ++i)
    {
        for (int j = 0; j < numberOfColumns; ++j)
            std::cout << matrix[j][i] << ' ';
        std::cout << std::endl;
    }
}

void swapPInt(int *&a, int *&b)
{
    int *c = a;
    a = b;
    b = c;
}

void Matrix::sortColumns(const int first, const int last)
{
    if (first >= last)
        return;
    swapPInt(matrix[first], matrix[(first + last) / 2]);
    int lastOfTheFirstPart = first;
    for (int i = first + 1; i <= last; i++)
        if (matrix[i][0] < matrix[first][0]) {
            ++lastOfTheFirstPart;
            swapPInt(matrix[i], matrix[lastOfTheFirstPart]);
        }
    swapPInt(matrix[first], matrix[lastOfTheFirstPart]);
    sortColumns(0, lastOfTheFirstPart - 1);
    sortColumns(lastOfTheFirstPart + 1, last);
}

void Matrix::sortColumns()
{
    sortColumns(0, numberOfColumns - 1);
}
