#include <cstring>

const int hashSize = 100;

struct HashTableElement
{
    char *string;
    HashTableElement *next;
};

struct StringHashTable
{
    HashTableElement *table[hashSize];
};

int hash(const char string[])
{
    int result = 0;
    for (int i = 0; string[i] != '\0'; ++i)
        result = (result + string[i]) % hashSize;
    return result;
}

StringHashTable *createStringHashTable()
{
    StringHashTable *newTable = new StringHashTable;
    for (int i = 0; i < hashSize; ++i)
    {
        newTable->table[i] = NULL;
    }
    return newTable;
}

HashTableElement *createHashTableElement(const char string[])
{
    HashTableElement *newElement = new HashTableElement;
    newElement->string = new char[strlen(string) + 1];
    strcpy(newElement->string, string);
    newElement->next = NULL;
    return newElement;
}

void addToStringHashTable(StringHashTable *table, const char string[])
{
    int value = hash(string);
    if (table->table[value] == NULL)
    {
        table->table[value] = createHashTableElement(string);
    }
    else
    {
        HashTableElement *currentElement = table->table[value];
        while (true)
        {
            if (strcmp(currentElement->string, string) == 0)
                break;
            else if (currentElement->next == NULL)
            {
                currentElement->next = createHashTableElement(string);
                break;
            }
            currentElement = currentElement->next;
        }
    }
}


bool existInStringHashTable(StringHashTable *table, const char string[])
{
    HashTableElement *currentElement = table->table[hash(string)];
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->string, string) == 0)
            return true;
        else
            currentElement = currentElement->next;
    }
    return false;
}

void deleteStringHashTable(StringHashTable *table)
{
    for (int i = 0; i < hashSize; ++i)
    {
        HashTableElement *removingElement = table->table[i];
        HashTableElement *nextElement = NULL;
        while (removingElement != NULL)
        {
            nextElement = removingElement->next;
            delete[] removingElement->string;
            delete removingElement;
            removingElement = nextElement;
        }
    }
    delete table;
}

