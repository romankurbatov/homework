#include <cstdio>
#include "filePrinter.h"

FilePrinter::FilePrinter(const char *filename)
{
    file = fopen(filename, "w");
}

FilePrinter::~FilePrinter()
{
    fclose(file);
}

void FilePrinter::printInt(const int number) const
{
    fprintf(file, "%d ", number);
}

void FilePrinter::putEndOfLine() const
{
    fputc('\n', file);
}
