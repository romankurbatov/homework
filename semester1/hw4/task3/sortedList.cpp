#include <iostream>

struct SortedListItem
{
    int value;
    SortedListItem *next;
};

struct SortedList
{
    SortedListItem *head;
};

SortedList *createSortedList()
{
    SortedList *list = new SortedList;
    list->head = NULL;
    return list;
}

void addToSortedList(SortedList *list, int value)
{
    if (list->head == NULL || list->head->value > value)
    {
        SortedListItem *newItem = new SortedListItem;
        newItem->value = value;
        newItem->next = list->head;
        list->head = newItem;
    }
    else if (list->head->value < value)
    {
        SortedListItem *currentItem = list->head;
        while (currentItem->next != NULL && currentItem->next->value <= value)
            currentItem = currentItem->next;
        if (currentItem->value != value)
        {
            SortedListItem *newItem = new SortedListItem;
            newItem->value = value;
            newItem->next = currentItem->next;
            currentItem->next = newItem;
        }
    }
}

void removeFromSortedList(SortedList *list, int value)
{
    if (list->head == NULL || list->head->value > value)
    {
        std::cout << "Нет такого числа в списке!" << std::endl;
    }
    else if (list->head->value == value)
    {
        SortedListItem *itemToRemove = list->head;
        list->head = list->head->next;
        delete itemToRemove;
    }
    else
    {
        SortedListItem *currentItem = list->head;
        while (currentItem->next != NULL && currentItem->next->value < value)
            currentItem = currentItem->next;
        if (currentItem->next != NULL && currentItem->next->value == value)
        {
            SortedListItem *itemToDelete = currentItem->next;
            currentItem->next = currentItem->next->next;
            delete itemToDelete;
        }
        else
        {
            std::cout << "Нет такого числа в списке!" << std::endl;
        }
    }
}

void deleteSortedList(SortedList *list)
{
    SortedListItem *currentItem = list->head;
    while (currentItem != NULL)
    {
        SortedListItem *nextItem = currentItem->next;
        delete currentItem;
        currentItem = nextItem;
    }
    delete list;
}

void printSortedList(SortedList *list)
{
    std::cout << "Сортированный список: ";
    SortedListItem *currentItem = list->head;
    while (currentItem != NULL)
    {
        std::cout << currentItem->value << ' ';
        currentItem = currentItem->next;
    }
    std::cout << std::endl;
}
