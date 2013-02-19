#pragma once

struct WordHashTable;

WordHashTable *createWordHashTable();
void addToWordHashTable(WordHashTable *table, const char word[]);
void deleteWordHashTable(WordHashTable *table);
void printWordsFromHashTable(WordHashTable *table);
void showDistribution(WordHashTable *table);
