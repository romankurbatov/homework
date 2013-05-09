#pragma once

#include "wordList.h"
#include <string>

class HashTable
{
public:
    typedef int HashFunction(const std::string &word, const int hashSize);
    HashTable(HashFunction *hash, const int size = 10);
    ~HashTable();
    void add(const std::string &word);
    void remove(const std::string &word);
    void showStatistics() const;
    void changeHashFunction(HashFunction *hash);
    bool isInTable(const std::string &word) const;
    void print() const;
private:
    HashFunction *hash;
    const int size;
    WordList *table;
};

