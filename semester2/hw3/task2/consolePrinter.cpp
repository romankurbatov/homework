#include <iostream>
#include "consolePrinter.h"

void ConsolePrinter::printInt(const int number) const
{
    std::cout << number << ' ';
}

void ConsolePrinter::putEndOfLine() const
{
    std::cout << std::endl;
}
