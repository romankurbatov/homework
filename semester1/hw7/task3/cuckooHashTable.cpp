#include <cstdio>
#include <cstring>

struct HashTableItem
{
    char *word;
    int numberOfOccurrences;
};

struct CuckooHashTable
{
    int size;
    HashTableItem **table[2];
};


CuckooHashTable *createHashTable()
{
    CuckooHashTable *hashTable = new CuckooHashTable;
    hashTable->size = 100;
    hashTable->table[0] = new HashTableItem*[hashTable->size];
    hashTable->table[1] = new HashTableItem*[hashTable->size];
    for (int i = 0; i < hashTable->size; ++i)
    {
        hashTable->table[0][i] = NULL;
        hashTable->table[1][i] = NULL;
    }
    return hashTable;
}

int hash(const char word[], const int hashSize, const int functionNumber)
{
    int result = 0;
    if (functionNumber == 0)
    {
        for (int i = 0; word[i] != '\0'; ++i)
            result = (result + word[i]) % hashSize;
    }
    else
    {
        for (int i = 0; word[i] != '\0'; ++i)
            result = (word[i] + 31 * result) % hashSize;
    }
    return result;
}

//Функция insert ставит на новое место элемент, "выгнанный" с его предыдущего места
void insert(CuckooHashTable *table, HashTableItem *item, const int numberOfTable)
{
    if (item == NULL)
        return;
    int hashValue = hash(item->word, table->size, numberOfTable);
    HashTableItem *previousItem = table->table[numberOfTable][hashValue];
    table->table[numberOfTable][hashValue] = item;
    insert(table, previousItem, (numberOfTable == 0) ? 1 : 0);
}

void addToHashTable(CuckooHashTable *table, const char word[])
{
    int value0 = hash(word, table->size, 0);
    int value1 = hash(word, table->size, 1);
    if (table->table[0][value0] != NULL && strcmp(table->table[0][value0]->word, word) == 0)
        ++table->table[0][value0]->numberOfOccurrences;
    else if (table->table[1][value1] != NULL && strcmp(table->table[1][value1]->word, word) == 0)
        ++table->table[1][value1]->numberOfOccurrences;
    else
    {
        HashTableItem *newItem = new HashTableItem;
        newItem->word = new char[strlen(word) + 1];
        strcpy(newItem->word, word);
        newItem->numberOfOccurrences = 1;
        if (table->table[0][value0] == NULL)
            table->table[0][value0] = newItem;
        else if (table->table[1][value1] == NULL)
            table->table[1][value1] = newItem;
        else
        {
            HashTableItem *previousItem = table->table[1][value0];
            table->table[0][value0] = newItem;
            insert(table, previousItem, 1);
        }
    }
}


void deleteHashTable(CuckooHashTable *table)
{
    for (int i = 0; i < table->size; ++i)
    {
        if (table->table[0][i] != NULL)
        {
            delete[] table->table[0][i]->word;
            delete table->table[0][i];
        }
        if (table->table[1][i] != NULL)
        {
            delete[] table->table[1][i]->word;
            delete table->table[1][i];
        }
    }
    delete[] table->table[0];
    delete[] table->table[1];
    delete table;
}

void printWordsFromHashTable(CuckooHashTable *table)
{
    printf("Частота использования слов:\n");
    for (int i = 0; i < table->size; ++i)
    {
        if (table->table[0][i] != NULL)
            printf("%s %d\n", table->table[0][i]->word, table->table[0][i]->numberOfOccurrences);
        if (table->table[1][i] != NULL)
            printf("%s %d\n", table->table[1][i]->word, table->table[1][i]->numberOfOccurrences);
    }
}
