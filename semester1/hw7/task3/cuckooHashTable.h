#pragma once

struct CuckooHashTable;

CuckooHashTable *createHashTable();
void addToHashTable(CuckooHashTable *table, const char word[]);
void deleteHashTable(CuckooHashTable *table);
void printWordsFromHashTable(CuckooHashTable *table);
