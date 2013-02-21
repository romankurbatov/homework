#include <cstdio>

struct DoubleStackItem
{
    double number;
    DoubleStackItem *next;
};

struct DoubleStack
{
    DoubleStackItem *top;
};

DoubleStack *createDoubleStack()
{
    DoubleStack *stack = new DoubleStack;
    stack->top = NULL;
    return stack;
}

void pushDouble(DoubleStack *stack, double number)
{
    DoubleStackItem *newItem = new DoubleStackItem;
    newItem->number = number;
    newItem->next = stack->top;
    stack->top = newItem;
}

double popDouble(DoubleStack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    else
    {
        double number = stack->top->number;
        DoubleStackItem *itemToRemove = stack->top;
        stack->top = stack->top->next;
        delete itemToRemove;
        return number;
    }
}

void deleteDoubleStack(DoubleStack *stack)
{
    DoubleStackItem *currentItem = stack->top;
    while (currentItem != NULL)
    {
        DoubleStackItem *nextItem = currentItem->next;
        delete currentItem;
        currentItem = nextItem;
    }
    delete stack;
}
