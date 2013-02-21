#include <cstdio>
#include <cstring>
#include "phoneBook.h"

int main()
{
    preparePhoneBook();
    while (true)
    {
        printf("Телефонный справочник\n");
        printf("Список операций:\n");
        printf("0 - выйти\n");
        printf("1 - добавить запись (имя и телефон)\n");
        printf("2 - найти телефон по имени\n");
        printf("3 - найти имя по телефону\n");
        printf("4 - сохранить текущие данные в файл\n");
        printf("Введите номер операции: ");
        int operationNumber = 0;
        scanf("%d", &operationNumber);
        fgetc(stdin);   //считываем символ конца строки, оставшийся после scanf,
                        //для правильной работы fgets в дальнейшем
        switch(operationNumber)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                char name[maxName];
                printf("Имя: ");
                fgets(name, maxName, stdin);
                char phone[maxPhone];
                printf("Телефон: ");
                fgets(phone, maxPhone, stdin);
                addToPhoneBook(name, phone);
                break;
            }
            case 2:
            {
                printf("Имя: ");
                char name[maxName];
                fgets(name, maxName, stdin);
                char *phone = findPhoneByName(name);
                if (phone != NULL)
                    printf("Телефон: %s", phone);
                else
                    printf("Такой записи не существует!\n");
                break;
            }
            case 3:
            {
                printf("Телефон: ");
                char phone[maxPhone];
                fgets(phone, maxPhone, stdin);
                char *name = findNameByPhone(phone);
                if (name != NULL)
                    printf("Имя: %s", name);
                else
                    printf("Такой записи не существует!\n");
                break;
            }
            case 4:
            {
                savePhoneBook();
                break;
            }
            default:
            {
                printf("Нет операции с таким номером!\n");
                break;
            }
        }
    }
}
