#include <iostream>
#include <cstdlib>

int countDigits(int n)
{
    if (n < 0)
        n *= -1;
    int numberOfDigits = 0;
    while (n != 0)
    {
        ++numberOfDigits;
        n /= 10;
    }
    return numberOfDigits;
}

void printRow(int degree, int *coefficients,
              int *numberOfDigitsInCoefficients, int *numberOfDigitsInExponents,
              int row)
{
    if (row != 1 && row != 2)
        return;

    bool firstTerm = true; //первый ненулевой член
    for (int i = degree; i >= 0; --i)
    {
        if (coefficients[i] == 0)   //если коэффициент равен нулю,
            continue;               //этот член выводиться не будет

        //знак
        if (firstTerm)
        {
            firstTerm = false;
            if (coefficients[i] < 0)
            {
                if (row == 1)
                    std::cout << ' ';
                else
                    std::cout << '-';
            }
        }
        else
        {
            if (row == 1)
                std::cout << ' ';
            else if (coefficients[i] > 0)
                std::cout << '+';
            else
                std::cout << '-';
        }

        //коэффициент
        if (coefficients[i] != 1 && coefficients[i] != -1)
        {
            if (row == 1)
                for (int j = 0; j < numberOfDigitsInCoefficients[i]; ++j)
                    std::cout << ' ';
            else
                std::cout << abs(coefficients[i]);
        }

        //переменная
        if (i != 0)
        {
            if (row == 1)
                std::cout << ' ';
            else
                std::cout << 'x';
        }

        //показатель степени
        if (i > 1)
        {
            if (row == 1)
                std::cout << i;
            else
                for (int j = 0; j < numberOfDigitsInExponents[i]; ++j)
                    std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void printPolynomial(int degree, int *coefficients)
{
    int *numberOfDigitsInCoefficients = new int[degree + 1]; //число цифр в коэффициентах
    for (int i = 0; i <= degree; ++i)
        numberOfDigitsInCoefficients[i] = countDigits(coefficients[i]);

    int *numberOfDigitsInExponents = new int[degree + 1]; //число цифр в показателях степени
    for (int i = 0; i <= degree; ++i)
        numberOfDigitsInExponents[i] = countDigits(i);

    printRow(degree, coefficients,
             numberOfDigitsInCoefficients, numberOfDigitsInExponents,
             1);
    printRow(degree, coefficients,
             numberOfDigitsInCoefficients, numberOfDigitsInExponents,
             2);

    delete[] numberOfDigitsInCoefficients;
    delete[] numberOfDigitsInExponents;
}

int main()
{
    std::cout << "Введите степень многочлена: ";
    int degree = 0;
    std::cin >> degree;

    int *coefficients = new int[degree + 1];
    for (int i = 0; i <= degree; ++i)
        coefficients[i] = 0;
    std::cout << "Введите коэффициенты при степенях переменной, начиная со старшей: ";
    for (int i = degree; i >= 0; --i)
        std::cin >> coefficients[i];

    printPolynomial(degree, coefficients);
    delete[] coefficients;
}

