#pragma once
#include <cstdio>
#include "printer.h"

class FilePrinter : public Printer
{
public:
    FilePrinter(const char *filename);
    ~FilePrinter();
protected:
    void printInt(const int number) const;
    void putEndOfLine() const;
private:
    FILE *file;
};
