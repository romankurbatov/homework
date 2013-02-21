#include <iostream>

int main()
{
    const int max = 1000;

    std::cout << "n=";
    int n = 0;
    std::cin >> n;

    bool prime[max + 1];
    for (int i = 0; i <= max; i++) {
        prime[i] = true;
    }

    for (int i = 2; i < n; i++)
        if (prime[i])
            for (int j = 2 * i; j <= n; j += i)
                prime[j] = false;

    int numberOfPrime = 0;
    for (int i = 2; i <= n; i++)
        if (prime[i])
            numberOfPrime++;

    std::cout << "Количество простых чисел, не превосходящих n: "
              << numberOfPrime << std::endl;
}

