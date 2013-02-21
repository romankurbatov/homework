#pragma once

struct DoubleStack;

DoubleStack *createDoubleStack();
void pushDouble(DoubleStack *stack, double number);
double popDouble(DoubleStack *stack);
void deleteDoubleStack(DoubleStack *stack);
