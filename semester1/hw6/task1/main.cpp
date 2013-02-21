#include <cstdio>
#include <binarySearchTree.h>

int main()
{
    BinarySearchTree *tree = createBinarySearchTree();
    printf("Тестирование двоичного дерева поиска\n");
    while (true)
    {
        printf("Возможные действия:\n");
        printf("0 - выход\n");
        printf("1 - добавить элемент в дерево\n");
        printf("2 - удалить элемент из дерева\n");
        printf("3 - проверить, есть ли элемент в дереве\n");
        printf("4 - вывести элементы в порядке возрастания\n");
        printf("5 - вывести элементы в порядке убывания\n");
        printf("Введите номер действия: ");
        int operationNumber = 0;
        scanf("%d", &operationNumber);
        switch (operationNumber)
        {
            case 0:
            {
                deleteBinarySearchTree(tree);
                return 0;
            }
            case 1:
            {
                printf("Введите элемент для добавления: ");
                int value = 0;
                scanf("%d", &value);
                addToBinarySearchTree(tree, value);
                break;
            }
            case 2:
            {
                printf("Введите элемент для удаления: ");
                int value = 0;
                scanf("%d", &value);
                removeFromBinarySearchTree(tree, value);
                break;
            }
            case 3:
            {
                printf("Введите элемент для проверки: ");
                int value = 0;
                scanf("%d", &value);
                if (existsInBinarySearchTree(tree, value))
                    printf("Элемент найден\n");
                else
                    printf("Элемент не найден\n");
                break;
            }
            case 4:
            {
                printLowToHigh(tree);
                break;
            }
            case 5:
            {
                printHighToLow(tree);
                break;
            }
            default:
            {
                printf("Некорректный номер действия\n");
                break;
            }
        }
    }
}

