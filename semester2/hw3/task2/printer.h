#pragma once

class Printer
{
public:
    virtual ~Printer()
    {

    }

    void print(int **matrix, const int dimension) const;
protected:
    virtual void printInt(const int number) const = 0;
    virtual void putEndOfLine() const = 0;
};
