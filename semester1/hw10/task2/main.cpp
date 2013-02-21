#include <cstdio>
#include <cctype>

int main()
{
    char c = EOF;
    int mantissa = 0;
    int pow10 = 1;
    int mantissaSign = 1;
    int exponent = 0;
    int exponentSign = 1;
    int state = 0;
    printf("Введите число: ");
    while (true)
    {
        switch (state)
        {
            case 0:
            {
                c = getchar();
                if (isdigit(c))
                    state = 2;
                else if (c == '-')
                    state = 1;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 1:
            {
                mantissaSign = -1;
                c = getchar();
                if (isdigit(c))
                    state = 2;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 2:
            {
                mantissa = mantissa * 10 + (c - '0');
                c = getchar();
                if (isdigit(c))
                    state = 2;
                else if (c == '.')
                    state = 3;
                else if (c == 'E' || c == 'e')
                    state = 5;
                else if (c == '\n' || c == EOF)
                    state = 8;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 3:
            {
                c = getchar();
                if (isdigit(c))
                    state = 4;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 4:
            {
                mantissa = mantissa * 10 + (c - '0');
                pow10 *= 10;
                c = getchar();
                if (isdigit(c))
                    state = 4;
                else if (c == 'E' || c == 'e')
                    state = 5;
                else if (c == '\n' || c == EOF)
                    state = 8;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 5:
            {
                c = getchar();
                if (c == '-')
                    state = 6;
                else if (isdigit(c))
                    state = 7;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 6:
            {
                exponentSign = -1;
                c = getchar();
                if (isdigit(c))
                    state = 7;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 7:
            {
                exponent = exponent * 10 + (c - '0');
                c = getchar();
                if (isdigit(c))
                    state = 7;
                else if (c == '\n' || c == EOF)
                    state = 8;
                else
                {
                    printf("Некорректная строка\n");
                    return 0;
                }
                break;
            }
            case 8:
            {
                double result = mantissaSign * (double) mantissa / pow10;
                if (exponentSign == 1)
                {
                    for (int i = 1; i <= exponent; ++i)
                        result *= 10;
                }
                else
                {
                    for (int i = 1; i <= exponent; ++i)
                        result /= 10;
                }
                printf("Было считано число %g\n", result);
                return 0;
            }
        }
    }
}

