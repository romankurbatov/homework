#include <cstdio>

//Перестановка формируется в массиве permutation. В массиве used на i-м месте стоит true,
//если число i+1 уже использовано в данной перестановке, и false  в противном случае.
//Функции generate при помощи параметра posedNumbers передаётся количество чисел, уже поставленных
//в перестановку. Если оно равно длине перестановки, её генерация окончена и её нужно
//вывести. Иначе перебираются все числа от 1 до n. Для каждого из них, ещё не используемого
//в данной перестановке, производится следующее: оно ставится ставится в перестановку,
//помечается в массиве used как использованное, а затем функция generate запускается снова,
//но уже с параметром posedNumbers, увеличенным на единицу. После её выполнения оно снова
//помечается в массиве used как неиспользованное.

int length = 0;
bool *used = NULL;
int *permutation = NULL;

void generate(int posedNumbers)
{
    if (posedNumbers == length)
    {
        for (int i = 0; i < length; ++i)
            printf("%d ", permutation[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < length; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            permutation[posedNumbers] = i + 1;
            generate(posedNumbers + 1);
            used[i] = false;
        }
    }
}

int main()
{
    printf("Программа генерации перестановок\n");
    printf("Введите длину перестановки: ");
    scanf("%d", &length);

    used = new bool[length];
    for (int i = 0; i < length; ++i)
        used[i] = false;

    permutation = new int[length];
    for (int i = 0; i < length; ++i)
        permutation[i] = 0;

    generate(0);
    delete[] permutation;
    delete[] used;
}

