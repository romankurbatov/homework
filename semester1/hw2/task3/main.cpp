#include <iostream>

const int maxNum = 1000;
int terms[maxNum + 1] = {};

void nextTerm(const int n, const int termNumber)
{
    if (n == 0) {
        std::cout << terms[0] << '=';
        for (int i = 1; i <= termNumber - 2; i++)
            std::cout << terms[i] << '+';
        std::cout << terms[termNumber - 1];
        std::cout << std::endl;
    } else {
        for (int i = 1; i <= terms[termNumber - 1] && i <= n; i++) {
            terms[termNumber] = i;
            nextTerm(n - i, termNumber + 1);
        }
    }
}

void printTerms(const int n)
{
    terms[0] = n;
    nextTerm(n, 1);
}

void performTest(const int numberOfTest, const int n)
{
    std::cout << "Тест " << numberOfTest << std::endl;
    std::cout << "Представляем число " << n << " суммой натуральных слагаемых:"
              << std::endl;
    printTerms(n);
    std::cout << std::endl;
}

void testing()
{
    performTest(1, 5);
    performTest(2, 6);
}

int main()
{
    testing();

    std::cout << "n=";
    int n = 0;
    std::cin >> n;
    printTerms(n);
}

