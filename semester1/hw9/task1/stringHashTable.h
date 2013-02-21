#pragma once

struct StringHashTable;

StringHashTable *createStringHashTable();
void addToStringHashTable(StringHashTable *table, const char string[]);
bool existInStringHashTable(StringHashTable *table, const char string[]);
void deleteStringHashTable(StringHashTable *table);
