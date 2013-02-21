#include <cstdlib>

struct ListItem
{
    int number;
    ListItem *next;
};

struct CircularList
{
    ListItem *head;
};

CircularList *createCircularList(int numberOfItems)
{
    if (numberOfItems <= 0)
        return NULL;

    CircularList *list = new CircularList;
    list->head = new ListItem;
    list->head->number = 1;
    list->head->next = NULL;

    ListItem *current = list->head;
    for (int i = 2; i <= numberOfItems; i++)
    {
        current->next = new ListItem;
        current = current->next;
        current->number = i;
    }
    current->next = list->head;
    return list;
}

int count(CircularList *list, int itemToDelete)
{
    if (itemToDelete <= 0)
        return 0;

    ListItem *current = list->head;
    while (current->next != current)
    {
        if (itemToDelete == 1)
        {
            ListItem *first = current;
            while (current->next != first)
                current = current->next;
        }
        else
        {
            for (int i = 2; i <= itemToDelete - 1; i++)
                current = current->next;
        }
        ListItem *removing = current->next;
        current->next = removing->next;
        delete removing;
        current = current->next;
    }
    int last = current->number;
    delete current;
    delete list;
    return last;
}
