#include <cstdio>
#include "parseTree.h"

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }
    ParseTree *tree = getParseTree(file);
    printf("Дерево разбора: ");
    printParseTree(tree);
    putchar('\n');
    printf("Значение выражения: %g\n", calculate(tree));
    deleteParseTree(tree);
    fclose(file);
}

