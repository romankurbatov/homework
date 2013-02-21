#include <cstdio>
#include <cstring>

const int modulo = 1000;

int hash(const char str[], int length)
{
    int result = 0;
    for (int i = 0; i < length; ++i)
    {
        result = (result + str[i]) % modulo;
    }
    return result;
}

int nextHash(const int prevHash, const char removingChar, const char newChar)
{
    return (prevHash - removingChar + newChar) % modulo;
}

bool equal(const char s[], const char t[], int length)
{
    int i = 0;
    for (i = 0; i < length; ++i)
    {
        if (s[i] != t[i])
            break;
    }
    return (i == length);
}

int search(const char subStr[], const char str[])
{
    int strLen = strlen(str);
    int subStrLen = strlen(subStr);
    int subStrHash = hash(subStr, subStrLen);
    int strHash = 0;
    for (int i = 0; i <= strLen - subStrLen; ++i)
    {
        if (i == 0)
            strHash = hash(str, subStrLen);
        else
            strHash = nextHash(strHash, str[i - 1], str[i + subStrLen - 1]);
        if (strHash == subStrHash)
            if (equal(str + i, subStr, subStrLen))
                return i;
    }
    return -1;
}

int main()
{
    const int maxLength = 100;

    char str[maxLength];
    str[0] = '\0';
    printf("Введите строку, в которой будем осуществлять поиск: ");
    fgets(str, maxLength, stdin);
    str[strlen(str) - 1] = '\0';

    char subStr[maxLength];
    subStr[0] = '\0';
    printf("Введите образец, который будем искать: ");
    fgets(subStr, maxLength, stdin);
    subStr[strlen(subStr) - 1] = '\0';

    int pos = search(subStr, str);
    if (pos == -1)
        printf("Образец в строке не найден\n");
    else
        printf("Образец входит в строку начиная с позиции %d (считая с нуля)\n", pos);
}

