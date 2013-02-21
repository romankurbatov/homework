#pragma once

struct SortedList;

SortedList *createSortedList();
void addToSortedList(SortedList *list, int value);
void removeFromSortedList(SortedList *list, int value);
void deleteSortedList(SortedList *list);
void printSortedList(SortedList *list);
