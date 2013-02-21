#include <iostream>

struct Fraction {
    int numerator;
    int denominator;
};

void printFractions(const Fraction firstFract, const Fraction secondFract, const int maxDenominator)
{
    const Fraction newFract = { firstFract.numerator + secondFract.numerator, firstFract.denominator + secondFract.denominator };
    if (newFract.denominator <= maxDenominator) {
        printFractions(firstFract, newFract, maxDenominator);
        std::cout << newFract.numerator << '/' << newFract.denominator << std::endl;
        printFractions(newFract, secondFract, maxDenominator);
    }
}

int main()
{
    std::cout << "N=";
    int N = 0;
    std::cin >> N;
    const Fraction zeroFract = { 0, 1 };
    const Fraction oneFract = { 1, 1 };
    std::cout << "Дроби от 0 до 1 со знаменателем, не превосходящим N:" << std::endl;
    printFractions(zeroFract, oneFract, N);
}

