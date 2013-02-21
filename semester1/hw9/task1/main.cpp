#include <cstdio>
#include <stringHashTable.h>

int main()
{
    const int maxString = 100;

    FILE *file1 = fopen("file1.txt", "r");
    if (file1 == NULL)
        return 0;

    StringHashTable *table = createStringHashTable();
    char string[maxString];
    while (fgets(string, maxString, file1) != NULL)
        addToStringHashTable(table, string);
    fclose(file1);

    FILE *file2 = fopen("file2.txt", "r");
    if (file2 == NULL)
    {
        deleteStringHashTable(table);
        return 0;
    }

    FILE *file3 = fopen("file3.txt", "w");
    if (file3 == NULL)
    {
        fclose(file2);
        deleteStringHashTable(table);
    }

    while (fgets(string, maxString, file2) != NULL)
    {
        if (existInStringHashTable(table, string))
            fputs(string, file3);
    }

    deleteStringHashTable(table);
    fclose(file2);
    fclose(file3);
}

