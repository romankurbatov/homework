#include <iostream>

int main()
{
    enum Directions { up, down, left, right };

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

    int row = dimension / 2;
    int column = dimension / 2;
    Directions direction = right;
    int n = 1; //количество оставшихся клеток на данном отрезке
    int i = 0; //номер отрезка (начиная с нуля)
    while (row >= 0 && row < dimension && column >= 0 && column < dimension)
    {
        std::cout << matrix[row][column] << ' ';
        switch (direction)
        {
            case up:
            {
                --row;
                break;
            }
            case down:
            {
                ++row;
                break;
            }
            case left:
            {
                --column;
                break;
            }
            case right:
            {
                ++column;
                break;
            }
        }
        --n;
        if (n == 0)
        {
            switch (direction)
            {
                case up:
                {
                    direction = right;
                    break;
                }
                case down:
                {
                    direction = left;
                    break;
                }
                case left:
                {
                    direction = up;
                    break;
                }
                case right:
                {
                    direction = down;
                    break;
                }
            }
            ++i;
            n = i / 2 + 1;
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < dimension; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

