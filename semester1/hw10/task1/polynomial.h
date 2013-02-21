#pragma once

struct Polynomial;

Polynomial *createPolynomial();
Polynomial *getPolynomial();
bool equals(Polynomial *p, Polynomial *q);
double value(Polynomial *p, double x);
void add(Polynomial *p, Polynomial *q, Polynomial *r);
void printPolynomial(Polynomial *p);
void deletePolynomial(Polynomial *p);
