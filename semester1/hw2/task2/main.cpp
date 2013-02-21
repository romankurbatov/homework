#include <iostream>

int power(const int a, int n)
{
    int res = 1;
    int p = a;
    while (n != 0) {
        int bit = n & 1;
        if (bit == 1)
            res *= p;

        n >>= 1;
        p *= p;
    }
    return res;
}

void performTest(const int numberOfTest, const int a, const int n)
{
    std::cout << "Тест " << numberOfTest << std::endl;
    std::cout << a << '^' << n << '=' << power(a, n) << std::endl;
    std::cout << std::endl;
}

void testing()
{
    performTest(1, 2, 5);
    performTest(2, 3, 6);
}

int main()
{
    testing();

    std::cout << "a=";
    int a = 0;
    std::cin >> a;
    std::cout << "n=";
    int n = 0;
    std::cin >> n;

    std::cout << a << '^' << n << '=' << power(a, n) << std::endl;
}
