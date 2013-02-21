#pragma once

const int maxName = 100;
const int maxPhone = 100;

void preparePhoneBook();
void addToPhoneBook(const char name[], const char phone[]);
char *findPhoneByName(const char name[]);
char *findNameByPhone(const char phone[]);
void savePhoneBook();
