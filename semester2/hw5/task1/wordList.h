#pragma once

#include <string>

class WordList
{
public:
    WordList();
    ~WordList();
    void add(const std::string &word);
    void remove(const std::string &word);
    int getLength() const;
    bool isInList(const std::string &word) const;
    void print();
private:
    class Node
    {
    public:
        Node(const std::string &word);
        const std::string &getWord() const;
        Node *getNext() const;
        void setNext(Node *next);
    private:
        std::string word;
        Node *next;
    };
    Node *head;
    int length;
};
