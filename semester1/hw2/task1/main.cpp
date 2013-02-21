#include <iostream>

long long fibonacciRec(const int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

long long fibonacciIter(const int n)
{
    if (n == 0 || n == 1)
        return 1;

    int prev[2] = { 0, 1 }; // два предыдущих числа Фибоначчи
                            // в начале работы первое из них не имеет значения,
                            // а второе равно 0-му числу Фибоначчи, т.е. 1

    int curr = 1;           // текущее число Фибоначчи, в начале работы
                            // здесь хранится 1-е число, т.е. 1

    for (int i = 2; i <= n; i++) {
        prev[0] = prev[1];
        prev[1] = curr;
        curr = prev[0] + prev[1];
    }
    return curr;
}

void performTest(const int numberOfTest, const int numberForCount)
{
    std::cout << "Тест " << numberOfTest << std::endl;
    std::cout << "Вычисляем " << numberForCount << "-е число Фибоначчи" << std::endl;
    std::cout << "Рекурсивно: " << fibonacciRec(numberForCount) << std::endl;
    std::cout << "Итеративно: " << fibonacciIter(numberForCount) << std::endl;
    std::cout << std::endl;
}

void testing()
{
    performTest(1, 10);
    performTest(2, 38);
}

int main()
{
    testing();

    std::cout << "n=";
    int n = 0;
    std::cin >> n;

    std::cout << "Вычисляем " << n << "-е число Фибоначчи" << std::endl;
    std::cout << "Рекурсивно: " << fibonacciRec(n) << std::endl;
    std::cout << "Итеративно: " << fibonacciIter(n) << std::endl;
}
