#include <cstdio>
#include <cstring>
#include "infixToPostfix.h"
#include "calculatePostfix.h"

const int maxExpression = 100;

int main()
{
    printf("Введите выражение: ");
    char infix[maxExpression];
    fgets(infix, maxExpression, stdin);
    infix[strlen(infix) - 1] = '\0';
    char postfix[maxExpression];
    infixToPostfix(infix, postfix);
    double result = calculatePostfix(postfix);
    printf("Результат: %g\n", result);
}

