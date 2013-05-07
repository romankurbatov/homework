#include <iostream>
#include <string>
#include "hashTable.h"

int hash1(const std::string &word, const int hashSize)
{
    int result = 0;
    int length = word.length();
    for (int i = 0; i < length; ++i)
        result = (result + static_cast<unsigned char>(word[i])) % hashSize;
    return result;
}

int hash2(const std::string &word, const int hashSize)
{
    int result = 0;
    int length = word.length();
    for (int i = 0; i < length; ++i)
        result = (static_cast<unsigned char>(word[i]) + 31 * result) % hashSize;
    return result;
}

HashTable::HashFunction *hash[] = { &hash1, &hash2 };

int main()
{
    int functionNumber = 0;
    HashTable table(hash[functionNumber]);
    enum Operations
    {
        add = 1,
        remove = 2,
        search = 3,
        statistics = 4,
        changeFunction = 5,
        print = 6,
        exit = 0
    };

    bool testingIsFinished = false;
    while (!testingIsFinished)
    {
        int operation = exit;
        std::cout << "Тестирование хеш-таблицы" << std::endl;
        std::cout << "Используется хеш-функция № " << functionNumber << std::endl;
        std::cout << "Возможные действия:" << std::endl
                  << add << " - добавить слово" << std::endl
                  << remove << " - удалить слово" << std::endl
                  << search << " - поиск слова" << std::endl
                  << statistics << " - показать статистику использования" << std::endl
                  << changeFunction << " - сменить хеш-функцию" << std::endl
                  << print << " - вывести таблицу" << std::endl
                  << exit << " - выход" << std::endl;
        std::cout << "Введите номер операции: ";
        std::cin >> operation;

        //удаляем из потока символы, оставшиеся после чтения номера действия
        std::string s;
        std::getline(std::cin, s);

        switch (operation)
        {
            case add:
            {
                std::cout << "Добавление слова" << std::endl;
                std::cout << "Введите слово: ";
                std::string word;
                std::getline(std::cin, word);
                table.add(word);
                std::cout << std::endl;
                break;
            }
            case remove:
            {
                std::cout << "Удаление слова" << std::endl;
                std::cout << "Введите слово: ";
                std::string word;
                std::getline(std::cin, word);
                table.remove(word);
                std::cout << std::endl;
                break;
            }
            case search:
            {
                std::cout << "Поиск слова" << std::endl;
                std::cout << "Введите слово: ";
                std::string word;
                std::getline(std::cin, word);
                if (table.isInTable(word))
                    std::cout << "Слово найдено" << std::endl;
                else
                    std::cout << "Слово не найдено" << std::endl;
                std::cout << std::endl;
                break;
            }
            case statistics:
            {
                std::cout << "Статистика использования" << std::endl;
                table.showStatistics();
                std::cout << std::endl;
                break;
            }
            case changeFunction:
            {
                if (functionNumber == 0)
                    functionNumber = 1;
                else
                    functionNumber = 0;
                table.changeHashFunction(hash[functionNumber]);
                std::cout << "Теперь используется хеш-функция №" << functionNumber << std::endl;
                std::cout << std::endl;
                break;
            }
            case print:
            {
                std::cout << "Вывод содержимого таблицы" << std::endl;
                table.print();
                std::cout << std::endl;
                break;
            }
            case exit:
            {
                testingIsFinished = true;
                break;
            }
            default:
            {
                std::cout << "Нет такого действия" << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
}

