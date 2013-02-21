#include <cstdio>
#include <cstring>
#include "phoneBook.h"
#include "getWord.h"

struct Contact
{
    char name[maxName];
    char phone[maxPhone];
};

const int bookSize = 100;

Contact book[bookSize];
int numberOfContacts = 0;

void preparePhoneBook()
{
    FILE *phoneBookFile = fopen("phonebook", "r");
    if (phoneBookFile != NULL)
    {
        fscanf(phoneBookFile, "%d", &numberOfContacts);
        fgetc(phoneBookFile);
        for (int i = 0; i < numberOfContacts; ++i)
        {
            fgets(book[i].name, maxName, phoneBookFile);
            fgets(book[i].phone, maxPhone, phoneBookFile);
        }
        fclose(phoneBookFile);
        phoneBookFile = NULL;
    }
}

int findContactByName(const char name[])
{
    for (int i = 0; i < numberOfContacts; ++i)
        if (strcmp(book[i].name, name) == 0)
            return i;
    return -1;
}

int findContactByPhone(const char phone[])
{
    for (int i = 0; i < numberOfContacts; ++i)
        if (strcmp(book[i].phone, phone) == 0)
            return i;
    return -1;
}

void addToPhoneBook(const char name[], const char phone[])
{
    int contactNumber = findContactByName(name);
    if (contactNumber != -1)
    {
        strcpy(book[contactNumber].phone, phone);
        return;
    }

    if (numberOfContacts == bookSize)
        return;
    strcpy(book[numberOfContacts].name, name);
    strcpy(book[numberOfContacts].phone, phone);
    ++numberOfContacts;
}

char *findPhoneByName(const char name[])
{
    int contactNumber = findContactByName(name);
    if (contactNumber == -1)
        return NULL;
    else
        return book[contactNumber].phone;
}

char *findNameByPhone(const char phone[])
{
    int contactNumber = findContactByPhone(phone);
    if (contactNumber == -1)
        return NULL;
    else
        return book[contactNumber].name;
}

void savePhoneBook()
{
    FILE *phoneBookFile = fopen("phonebook", "w");
    fprintf(phoneBookFile, "%d\n", numberOfContacts);
    for (int i = 0; i < numberOfContacts; ++i)
        fprintf(phoneBookFile, "%s%s", book[i].name, book[i].phone);
    fclose(phoneBookFile);
}

