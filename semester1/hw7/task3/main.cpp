#include <cstdio>
#include <cctype>
#include <cuckooHashTable.h>

//getWord считывает слово из файла input в символьный массив word.
//Длина слова - не более (maxLength - 1) символов.
//Если встретился конец файла, возвращает EOF, иначе - 0.
//Если файл кончился, когда уже несколько букв слова были считаны,
//возвращаем 0 и присваиваем статической булевой переменной foundEOF
//значение true. В следующий раз, не пытаясь считывать символы из файла,
//сразу возвращаем EOF.
int getWord(FILE *input, char word[], int maxLength)
{
    static bool foundEOF = false;

    word[0] = '\0';
    if (foundEOF)
        return EOF;

    int c = EOF;

    //пропускаем символы, не являющиеся буквами
    while (true)
    {
        c = fgetc(input);
        if (c == EOF)
            return EOF;
        if (isalpha(c))
            break;
    }

    word[0] = c;
    int length = 1;
    while (length < maxLength - 1)
    {
        c = fgetc(input);
        if (c == EOF)
        {
            foundEOF = true;
            break;
        }
        if (!isalpha(c))
            break;
        word[length] = c;
        ++length;
    }

    word[length] = '\0';
    return 0;
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }
    const int maxLength = 100;
    char word[maxLength];

    CuckooHashTable *hashTable = createHashTable();
    while (getWord(input, word, maxLength) != EOF)
    {
        addToHashTable(hashTable, word);
    }
    fclose(input);
    printWordsFromHashTable(hashTable);
    deleteHashTable(hashTable);
}

