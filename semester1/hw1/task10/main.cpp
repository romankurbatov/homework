#include <iostream>
#include <cstdio>
#include <cstring>

bool palindrome(const char s[])
{
    int len = std::strlen(s);
    int n = len / 2;
    int i = 0;
    for (i = 0; i < n; i++)
        if (s[i] != s[len - 1 - i])
            break;
    return (i == n);
}

void performTest(int n, const char s[])
{
    std::cout << "Тестовый набор " << n << std::endl;
    std::cout << "Строка \"" << s << "\"" << std::endl;
    if (palindrome(s))
        std::cout << "Палиндром" << std::endl;
    else
        std::cout << "Не палиндром" << std::endl;
    std::cout << std::endl;
}

void testing()
{
    performTest(1, "level");
    performTest(2, "Linux");
}

int main()
{
    testing();

    const int maxLine = 100;
	
    std::cout << "Введите строку (не более " << maxLine - 1 << " симв.):" << std::endl;
    char s[maxLine] = {};
    std::fgets(s, maxLine, stdin);
    s[std::strlen(s) - 1] = '\0'; // удаляем символ конца строки

    if (palindrome(s))
        std::cout << "Палиндром" << std::endl;
	else
        std::cout << "Не палиндром" << std::endl;
}
