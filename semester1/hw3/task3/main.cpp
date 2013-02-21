#include <cstdio>
#include "charStack.h"

int priority(char op)
{
    switch (op)
    {
        case '*': case '/':
        {
            return 2;
        }
        case '+': case '-':
        {
            return 1;
        }
        default:
        {
            return -1;
        }
    }
}

int main()
{
    CharStack *stack = createCharStack();

    printf("Преобразование выражения из инфиксной формы записи в постфиксную\n");
    printf("Введите выражение: ");

    int c = EOF;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        switch (c)
        {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9': case '0':
            {
                putchar(c);
                putchar(' ');
                break;
            }
            case '(':
            {
                pushChar(stack, '(');
                break;
            }
            case ')':
            {
                while ((c = popChar(stack)) != '(' && c != EOF)
                {
                    putchar(c);
                    putchar(' ');
                }
                if (c == EOF)
                {
                    putchar('\n');
                    printf("Некорректная расстановка скобок!\n");
                    deleteCharStack(stack);
                    return 1;
                }
                break;
            }
            case '+': case '-': case '*': case '/':
            {
                int c1 = EOF;
                while ((c1 = popChar(stack)) != EOF && c1 != '(' && priority(c) <= priority(c1))
                {
                    putchar(c1);
                    putchar(' ');
                }
                if (c1 != EOF)
                    pushChar(stack, c1);
                pushChar(stack, c);
                break;
            }
            default:
            {
                putchar('\n');
                printf("Некорректный символ во входной строке!\n");
                deleteCharStack(stack);
                return 1;
            }
        } //switch
    } //while
    while ((c = popChar(stack)) != EOF && c != '(')
    {
        putchar(c);
        putchar(' ');
    }
    putchar('\n');
    if (c == '(')
        printf("Некорректная расстановка скобок!\n");
    deleteCharStack(stack);
}

