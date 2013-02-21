#include <iostream>

struct Term
{
    double coefficient;
    int degree;
    Term *next;
};

struct Polynomial
{
    Term *firstTerm; //связный список слагаемых, отсортированный по возрастанию степени переменной
};

Polynomial *createPolynomial()
{
    Polynomial *p = new Polynomial;
    p->firstTerm = nullptr;
    return p;
}

Term *createTerm(double coefficient, int degree)
{
    Term *newTerm = new Term;
    newTerm->coefficient = coefficient;
    newTerm->degree = degree;
    newTerm->next = nullptr;
    return newTerm;
}

Term *copyTerm(Term *term)
{
    Term *newTerm = createTerm(term->coefficient, term->degree);
    return newTerm;
}

Polynomial *getPolynomial()
{
    Polynomial *p = createPolynomial();

    std::cout << "Введите степень многочлена: ";
    int degree = 0;
    std::cin >> degree;

    std::cout << "Введите коэффициенты многочлена при степенях переменной от 0 до " << degree << ": ";
    bool firstTerm = true;
    Term *currentTerm = nullptr;
    for (int i = 0; i <= degree; ++i)
    {
        int coefficient = 0;
        std::cin >> coefficient;
        if (coefficient == 0)
            continue;
        if (firstTerm)
        {
            p->firstTerm = createTerm(coefficient, i);
            currentTerm = p->firstTerm;
            firstTerm = false;
        }
        else
        {
            currentTerm->next = createTerm(coefficient, i);
            currentTerm = currentTerm->next;
        }
    }

    return p;
}

bool equals(Polynomial *p, Polynomial *q)
{
    Term* term1 = p->firstTerm;
    Term* term2 = q->firstTerm;

    while (true)
    {
        if (term1 == nullptr || term2 == nullptr)
        {
            return (term1 == nullptr && term2 == nullptr);
        }
        else
        {
            if (term1->coefficient == term2->coefficient && term1->degree == term2->degree)
            {
                term1 = term1->next;
                term2 = term2->next;
            }
            else
                return false;
        }
    }
}

double value(Polynomial *p, double x)
{
    Term *currentTerm = p->firstTerm;
    double result = 0;
    double power = 1;
    int previousDegree = 0;
    while (currentTerm != nullptr)
    {
        for (int i = previousDegree + 1; i <= currentTerm->degree; ++i)
            power *= x;
        result += currentTerm->coefficient * power;
        previousDegree = currentTerm->degree;
        currentTerm = currentTerm->next;
    }
    return result;
}

void add(Polynomial *p, Polynomial *q, Polynomial *r)
{
    bool firstTerm = true;
    Term *term1 = p->firstTerm;
    Term *term2 = q->firstTerm;
    Term *term3 = nullptr;
    while (term1 != nullptr || term2 != nullptr)
    {
        if (term1 == nullptr)
        {
            if (firstTerm)
            {
                firstTerm = false;
                r->firstTerm = copyTerm(term2);
                term2 = term2->next;
                term3 = r->firstTerm;
            }
            else
            {
                term3->next = copyTerm(term2);
                term2 = term2->next;
                term3 = term3->next;
            }
        }
        else if (term2 == nullptr)
        {
            if (firstTerm)
            {
                firstTerm = false;
                r->firstTerm = copyTerm(term1);
                term1 = term1->next;
                term3 = r->firstTerm;
            }
            else
            {
                term3->next = copyTerm(term1);
                term1 = term1->next;
                term3 = term3->next;
            }
        }
        else if (term1->degree < term2->degree)
        {
            if (firstTerm)
            {
                firstTerm = false;
                r->firstTerm = copyTerm(term1);
                term1 = term1->next;
                term3 = r->firstTerm;
            }
            else
            {
                term3->next = copyTerm(term1);
                term1 = term1->next;
                term3 = term3->next;
            }
        }
        else if (term2->degree < term1->degree)
        {
            if (firstTerm)
            {
                firstTerm = false;
                r->firstTerm = copyTerm(term2);
                term2 = term2->next;
                term3 = r->firstTerm;
            }
            else
            {
                term3->next = copyTerm(term2);
                term2 = term2->next;
                term3 = term3->next;
            }
        }
        else
        {
            double sum = term1->coefficient + term2->coefficient;
            if (sum != 0)
            {
                if (firstTerm)
                {
                    firstTerm = false;
                    r->firstTerm = createTerm(sum, term1->degree);
                    term3 = r->firstTerm;
                }
                else
                {
                    term3->next = createTerm(sum, term1->degree);
                    term3 = term3->next;
                }
            }
            term1 = term1->next;
            term2 = term2->next;
        }
    }
}

void printPolynomial(Polynomial *p)
{
    Term *currentTerm = p->firstTerm;
    if (currentTerm == nullptr)
    {
        std::cout << '0' << std::endl;
        return;
    }
    bool firstTerm = true;
    while (currentTerm != nullptr)
    {
        if (firstTerm)
            firstTerm = false;
        else
            std::cout << " + ";
        std::cout << currentTerm->coefficient;
        if (currentTerm->degree == 1)
            std::cout << "x";
        else if (currentTerm->degree > 1)
            std::cout << "x^" << currentTerm->degree;
        currentTerm = currentTerm->next;
    }
    std::cout << std::endl;
}

void deletePolynomial(Polynomial *p)
{
    Term *currentTerm = p->firstTerm;
    while (currentTerm != nullptr)
    {
        Term *removingTerm = currentTerm;
        currentTerm = currentTerm->next;
        delete removingTerm;
    }
    delete p;
}
