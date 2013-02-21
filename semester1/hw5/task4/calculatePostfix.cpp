#include <cstdio>
#include "doubleStack.h"

double calculatePostfix(const char expression[])
{
    DoubleStack *stack = createDoubleStack();
    char c = EOF;
    int i = 0;
    while (true)
    {
        c = expression[i];
        ++i;
        if (c == '\0')
            break;
        switch (c)
        {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9': case '0':
            {
                pushDouble(stack, c - '0');
                break;
            }
            case '+':
            {
                pushDouble(stack, popDouble(stack) + popDouble(stack));
                break;
            }
            case '-':
            {
                double operand2 = popDouble(stack);
                pushDouble(stack, popDouble(stack) - operand2);
                break;
            }
            case '*':
            {
                pushDouble(stack, popDouble(stack) * popDouble(stack));
                break;
            }
            case '/':
            {
                double operand2 = popDouble(stack);
                if (operand2 == 0)
                    break;
                pushDouble(stack, popDouble(stack) / operand2);
                break;
            }
        }
    }
    double result = popDouble(stack);
    deleteDoubleStack(stack);
    return result;
}

