#pragma once

class Matrix
{
public:
    Matrix(int numberOfRows, int numberOfColumns);
    ~Matrix();
    void fillRandom();
    void print() const;
    void sortColumns();
private:
    const int numberOfRows;
    const int numberOfColumns;
    int **matrix;
    static const int maxRandomElement = 99;
    void sortColumns(const int first, const int last);
};
