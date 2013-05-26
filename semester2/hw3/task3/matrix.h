#pragma once

class Matrix
{
public:
    Matrix(int numberOfRows, int numberOfColumns);
    ~Matrix();
    void fillRandom();
    void print() const;
    void sortColumns();
    int getNumberOfRows() const;
    int getNumberOfColumns() const;
    int getElement(const int row, const int column);
private:
    const int numberOfRows;
    const int numberOfColumns;
    int **matrix;
    static const int maxRandomElement = 99;
    void sortColumns(const int first, const int last);
};
