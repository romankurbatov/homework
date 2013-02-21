#pragma once

struct CharStack;

CharStack *createCharStack();
void pushChar(CharStack *stack, char symbol);
int popChar(CharStack *stack);
void deleteCharStack(CharStack *stack);
