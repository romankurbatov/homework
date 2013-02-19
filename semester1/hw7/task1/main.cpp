#include <iostream>

int main()
{
    std::cout << "Введите количество студентов: ";
    int numberOfStudents = 0;
    std::cin >> numberOfStudents;

    std::cout << "Введите количество списанных работ: ";
    int numberOfWorks = 0;
    std::cin >> numberOfWorks;

    int *copiedFrom = new int[numberOfStudents + 1];
    for (int i = 0; i <= numberOfStudents; ++i)
        copiedFrom[i] = 0;

    std::cout << "Введите парами номера студентов, кто у кого списал: " << std::endl;
    for (int i = 0; i < numberOfWorks; ++i)
    {
        int studentNumber = 0;
        std::cin >> studentNumber;
        std::cin >> copiedFrom[studentNumber];
    }

    for (int i = 4; i <= numberOfStudents; ++i)
    {
        if (copiedFrom[i] == 0)
        {
            std::cout << "Студент " << i << " не сдал ничего" << std::endl;
        }
        else
        {
            int author = copiedFrom[i];
            while (author > 3)
                author = copiedFrom[author];
            std::cout << "Студент " << i << " сдал решение студента " << author << std::endl;
        }
    }

    delete[] copiedFrom;
}

