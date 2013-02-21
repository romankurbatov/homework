#include <cstdio>

int main()
{
    printf("Введите число: ");
    double x = 0;
    scanf("%lf", &x);
    unsigned char *b = (unsigned char *) &x;
    int sign = b[7] >> 7;
    int exponent = (((int) (b[7] & 0x7F)) << 4) + (b[6] >> 4) - 1023;
    double fraction = 1;
    double divider = 16;
    fraction += (b[6] & 0x0F) / divider;
    for (int i = 5; i >= 0; --i)
    {
        divider *= 256;
        fraction += b[i] / divider;
    }
    printf("Результат: ");
    if (sign == 1)
        putchar('-');
    else
        putchar('+');
    printf("%.10f*2^(%d)\n", fraction, exponent);
}

