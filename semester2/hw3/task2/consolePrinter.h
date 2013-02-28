#pragma once
#include "printer.h"

class ConsolePrinter : public Printer
{
protected:
    void printInt(const int number) const;
    void putEndOfLine() const;
};
