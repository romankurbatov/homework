#include <cstdio>
#include <cstring>

const int hashSize = 100;

struct HashTableElement
{
    char *word;
    int numberOfOccurrences;
    HashTableElement *next;
};

struct WordHashTable
{
    HashTableElement *table[hashSize];
    int numberOfWords[hashSize];
};

int hash(const char word[])
{
    int result = 0;
    for (int i = 0; word[i] != '\0'; ++i)
        result = (result + word[i]) % hashSize;
    return result;
}

WordHashTable *createWordHashTable()
{
    WordHashTable *newTable = new WordHashTable;
    for (int i = 0; i < hashSize; ++i)
    {
        newTable->table[i] = NULL;
        newTable->numberOfWords[i] = 0;
    }
    return newTable;
}

HashTableElement *createHashTableElement(const char word[])
{
    HashTableElement *newElement = new HashTableElement;
    newElement->word = new char[strlen(word) + 1];
    strcpy(newElement->word, word);
    newElement->numberOfOccurrences = 1;
    newElement->next = NULL;
    return newElement;
}

void addToWordHashTable(WordHashTable *table, const char word[])
{
    int value = hash(word);
    if (table->table[value] == NULL)
    {
        table->table[value] = createHashTableElement(word);
        table->numberOfWords[value] = 1;
    }
    else
    {
        HashTableElement *currentElement = table->table[value];
        while (true)
        {
            if (strcmp(currentElement->word, word) == 0)
            {
                ++currentElement->numberOfOccurrences;
                break;
            }
            else if (currentElement->next == NULL)
            {
                currentElement->next = createHashTableElement(word);
                ++table->numberOfWords[value];
                break;
            }
            currentElement = currentElement->next;
        }
    }
}

void deleteWordHashTable(WordHashTable *table)
{
    for (int i = 0; i < hashSize; ++i)
    {
        HashTableElement *removingElement = table->table[i];
        HashTableElement *nextElement = NULL;
        while (removingElement != NULL)
        {
            nextElement = removingElement->next;
            delete[] removingElement->word;
            delete removingElement;
            removingElement = nextElement;
        }
    }
    delete table;
}

void printWordsFromHashTable(WordHashTable *table)
{
    printf("Число использований каждого слова в тексте:\n");
    for (int i = 0; i < hashSize; ++i)
    {
        HashTableElement *printingElement = table->table[i];
        while (printingElement != NULL)
        {
            printf("%s %d\n", printingElement->word, printingElement->numberOfOccurrences);
            printingElement = printingElement->next;
        }
    }
}

void showDistribution(WordHashTable *table)
{
    printf("Распределение слов по ячейкам хеш-таблицы:\n");
    for (int i = 0; i < hashSize; ++i)
        printf("%d %d\n", i, table->numberOfWords[i]);
}
