#include <iostream>
#include <cstdio>
#include <cstring>

int numberOfOccurrences(const char s1[], const char s[])
{
    int n = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int j = 0;
        while (s[i + j] == s1[j] && s1[j] != '\0')
            j++;
        if (s1[j] == '\0')
            n++;
    }

    return n;
}

void performTest(int n, const char s[], const char s1[])
{
    std::cout << "Тестовый набор " << n << std::endl;
    std::cout << "Строка s: \"" << s << "\"" << std::endl;
    std::cout << "Строка s1: \"" << s1 << "\"" << std::endl;
    std::cout << "Число вхождений s1 в s: " << numberOfOccurrences(s1, s) << std::endl;
    std::cout << std::endl;
}

void testing()
{
    performTest(1,
                "Can you can a can as a canner can can a can?",
                "can");

    performTest(2,
                "Косил косой косой косой",
                "косой");
}

int main()
{
    testing();

    const int maxLine = 100;

    char s[maxLine] = {};
    char s1[maxLine] = {};

    std::cout << "Введите строку s:" << std::endl;
    std::fgets(s, maxLine, stdin);
    s[std::strlen(s) - 1] = '\0'; // удаляем символ конца строки

    std::cout << "Введите строку s1:" << std::endl;
    std::fgets(s1, maxLine, stdin);
    s1[std::strlen(s1) - 1] = '\0'; // удаляем символ конца строки

    std::cout << "Число вхождений s1 в s: " << numberOfOccurrences(s1, s) << std::endl;
}

