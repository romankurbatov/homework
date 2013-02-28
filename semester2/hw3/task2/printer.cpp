#include "printer.h"

void Printer::print(int **matrix, const int dimension) const
{
    enum Directions { up, down, left, right };

    int row = dimension / 2;
    int column = dimension / 2;
    Directions direction = right;
    int n = 1; //количество оставшихся клеток на данном отрезке
    int i = 0; //номер отрезка (начиная с нуля)
    while (row >= 0 && row < dimension && column >= 0 && column < dimension)
    {
        printInt(matrix[row][column]);
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
    putEndOfLine();
}
