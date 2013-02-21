#pragma once

struct CircularList;

CircularList *createCircularList(int numberOfItems);
int count(CircularList *list, int itemToDelete);
