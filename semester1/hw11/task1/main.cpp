#include <cstdio>
#include <cstdlib>
#include <cctype>

double getNumber()
{
    enum States {
        begin,
        inMantissaAfterMinus,
        gettingMantissaBeforePoint,
        inMantissaAfterPoint,
        gettingMantissaAfterPoint,
        afterE,
        inExponentAfterMinus,
        gettingExponent,
        end,
        error
    };
    char c = EOF;
    int mantissa = 0;
    int pow10 = 1;
    int mantissaSign = 1;
    int exponent = 0;
    int exponentSign = 1;
    States state = begin;
    while (true)
    {
        switch (state)
        {
            case begin:
            {
                c = getchar();
                if (isdigit(c))
                    state = gettingMantissaBeforePoint;
                else if (c == '-')
                    state = inMantissaAfterMinus;
                else
                    state = error;
                break;
            }
            case inMantissaAfterMinus:
            {
                mantissaSign = -1;
                c = getchar();
                if (isdigit(c))
                    state = gettingMantissaBeforePoint;
                else
                    state = error;
                break;
            }
            case gettingMantissaBeforePoint:
            {
                mantissa = mantissa * 10 + (c - '0');
                c = getchar();
                if (isdigit(c))
                    state = gettingMantissaBeforePoint;
                else if (c == '.')
                    state = inMantissaAfterPoint;
                else if (c == 'E' || c == 'e')
                    state = afterE;
                else
                    state = end;
                break;
            }
            case inMantissaAfterPoint:
            {
                c = getchar();
                if (isdigit(c))
                    state = gettingMantissaAfterPoint;
                else
                    state = error;
                break;
            }
            case gettingMantissaAfterPoint:
            {
                mantissa = mantissa * 10 + (c - '0');
                pow10 *= 10;
                c = getchar();
                if (isdigit(c))
                    state = gettingMantissaAfterPoint;
                else if (c == 'E' || c == 'e')
                    state = afterE;
                else
                    state = end;
                break;
            }
            case afterE:
            {
                c = getchar();
                if (c == '-')
                    state = inExponentAfterMinus;
                else if (isdigit(c))
                    state = gettingExponent;
                else
                    state = error;
                break;
            }
            case inExponentAfterMinus:
            {
                exponentSign = -1;
                c = getchar();
                if (isdigit(c))
                    state = gettingExponent;
                else
                    state = error;
                break;
            }
            case gettingExponent:
            {
                exponent = exponent * 10 + (c - '0');
                c = getchar();
                if (isdigit(c))
                    state = gettingExponent;
                else
                    state = end;
                break;
            }
            case end:
            {
                ungetc(c, stdin);
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
                return result;
            }
            case error:
            {
                printf("Ошибка в выражении\n");
                exit(1);
            }
        }
    }
}

double expression();

double primary()
{
    int c = getchar();
    if (isdigit(c) || c == '-')
    {
        ungetc(c, stdin);
        return getNumber();
    }
    else if (c == '(')
    {
        double result = expression();
        if (getchar() != ')')
        {
            printf("Ошибка в выражении\n");
            exit(1);
        }
        return result;
    }
    else
    {
        printf("Ошибка в выражении\n");
        exit(1);
    }
}

double term()
{
    double result = primary();
    while (true)
    {
        int c = getchar();
        switch (c)
        {
            case '*':
            {
                result *= primary();
                break;
            }
            case '/':
            {
                double divisor = primary();
                if (divisor == 0)
                {
                    printf("Деление на ноль\n");
                    exit(1);
                }
                result /= divisor;
                break;
            }
            default:
            {
                ungetc(c, stdin);
                return result;
            }
        }
    }
}

double expression()
{
    double result = term();
    while (true)
    {
        int c = getchar();
        switch (c)
        {
            case '+':
            {
                result += term();
                break;
            }
            case '-':
            {
                result -= term();
                break;
            }
            default:
            {
                ungetc(c, stdin);
                return result;
            }
        }
    }
}

int main()
{
    printf("Введите выражение: ");
    double result = expression();
    if (fgetc(stdin) != '\n')
        printf("Ошибка в выражении\n");
    else
        printf("Значение выражения: %g\n", result);
}

