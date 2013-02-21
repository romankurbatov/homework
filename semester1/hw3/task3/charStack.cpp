#include <cstdio>

struct CharStackItem
{
    char symbol;
    CharStackItem *next;
};

struct CharStack
{
    CharStackItem *top;
};

CharStack *createCharStack()
{
    CharStack *stack = new CharStack;
    stack->top = NULL;
    return stack;
}

void pushChar(CharStack *stack, char symbol)
{
    CharStackItem *newItem = new CharStackItem;
    newItem->symbol = symbol;
    newItem->next = stack->top;
    stack->top = newItem;
}

int popChar(CharStack *stack)
{
    if (stack->top == NULL)
    {
        return EOF;
    }
    else
    {
        char symbol = stack->top->symbol;
        CharStackItem *itemToRemove = stack->top;
        stack->top = stack->top->next;
        delete itemToRemove;
        return symbol;
    }
}

void deleteCharStack(CharStack *stack)
{
    CharStackItem *currentItem = stack->top;
    while (currentItem != NULL)
    {
        CharStackItem *nextItem = currentItem->next;
        delete currentItem;
        currentItem = nextItem;
    }
    delete stack;
}
