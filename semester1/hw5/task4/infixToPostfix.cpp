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

int infixToPostfix(const char from[], char to[])
{
    CharStack *stack = createCharStack();

    int c = EOF;
    int i = 0;
    int j = 0;
    while (true)
    {
        c = from[i];
        ++i;
        if (c == '\0')
            break;
        switch (c)
        {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9': case '0':
            {
                to[j] = c;
                ++j;
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
                    to[j] = c;
                    ++j;
                }
                if (c == EOF)
                {
                    deleteCharStack(stack);
                    to[j] = '\0';
                    return 1;
                }
                break;
            }
            case '+': case '-': case '*': case '/':
            {
                int c1 = EOF;
                while ((c1 = popChar(stack)) != EOF && c1 != '(' && priority(c) <= priority(c1))
                {
                    to[j] = c1;
                    ++j;
                }
                if (c1 != EOF)
                    pushChar(stack, c1);
                pushChar(stack, c);
                break;
            }
            default:
            {
                deleteCharStack(stack);
                to[j] = '\0';
                return 2;
            }
        } //switch
    } //while
    while ((c = popChar(stack)) != EOF && c != '(')
    {
        to[j] = c;
        ++j;
    }
    deleteCharStack(stack);
    to[j] = '\0';
    if (c == '(')
        return 1;
    return 0;
}
