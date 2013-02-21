#include <cstdio>
#include <clocale>
#include <cwchar>

bool canBeConverted(const wchar_t s[], const wchar_t t[])
{
    const int len1 = wcslen(s);
    const int len2 = wcslen(t);

    if (len1 != len2)
        return false;
    const int len = len1;

    bool used[len];
    for (int i = 0; i < len; i++)
        used[i] = false;

    /*  Для каждого символа в строке s ищем совпадающий с ним и ещё не использованный символ
     *  в строке t. Меняем значение соответствующего элемента массива used на true. Если для
     *  какого-то символа из s такой символ в строке t найти не удалось, значит, строку
     *  s невозможно преобразовть в t перестановкой символов.
     */

    int i = 0;
    for (i = 0; i < len; i++)
    {
        int j = 0;
        for (j = 0; j < len; j++)
            if (t[j] == s[i] && !used[j])
            {
                used[j] = true;
                break;
            }

        if (j == len)
            break;
    }

    return (i == len);
}

void performTest(const wchar_t s[], const wchar_t t[])
{
    static int numberOfTest = 0;
    numberOfTest++;

    wprintf(L"Тест %d\n", numberOfTest);
    wprintf(L"Строка 1: \"%ls\"\n", s);
    wprintf(L"Строка 2: \"%ls\"\n", t);
    if (canBeConverted(s, t))
        wprintf(L"Из первой строки можно получить вторую\n");
    else
        wprintf(L"Из первой строки невозможно получить вторую\n");
    wprintf(L"\n");
}

void testing()
{
    performTest(L"апельсин", L"спаниель");
    performTest(L"абонент", L"абонемент");
}

int main()
{
    setlocale(LC_ALL, "");

    testing();

    const int maxLength = 100;

    wprintf(L"Введите первую строку:\n");
    wchar_t s[maxLength];
    fgetws(s, maxLength, stdin);
    s[wcslen(s) - 1] = '\0'; // удаляем символ конца строки

    wprintf(L"Введите вторую строку:\n");
    wchar_t t[maxLength];
    fgetws(t, maxLength, stdin);
    t[wcslen(t) - 1] = '\0'; // удаляем символ конца строки

    if (canBeConverted(s, t))
        wprintf(L"Из первой строки можно получить вторую\n");
    else
        wprintf(L"Из первой строки невозможно получить вторую\n");
}

