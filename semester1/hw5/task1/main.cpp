#include <cstdio>
#include <cctype>

void reset(bool array[], const int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = false;
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }

    const int numberOfLetters = ('Z' - 'A' + 1) + ('z' - 'a' + 1);
    bool *met = new bool[numberOfLetters];
    reset(met, numberOfLetters);
    int c = EOF;
    bool inWord = false;
    while ((c = fgetc(input)) != EOF)
    {
        if (isspace(c))
        {
            putchar(c);
            if (inWord)
            {
                inWord = false;
                reset(met, numberOfLetters);
            }
            continue;
        }
        inWord = true;
        if (!isalpha(c))
        {
            putchar(c);
            continue;
        }
        int numberInArray = 0;
        if (c >= 'A' && c <= 'Z')
            numberInArray = c - 'A';
        else
            numberInArray = ('Z' - 'A' + 1) + (c - 'a');
        if (!met[numberInArray])
        {
            putchar(c);
            met[numberInArray] = true;
        }
    }
    putchar('\n');
    delete[] met;
}

