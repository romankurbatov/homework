#include <cstdio>
#include <graph.h>

int main()
{
    Graph *graph = getGraph("input.txt");
    if (graph == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }
    int connectedComponents = countConnectedComponents(graph);
    printf("Количество компонент связности: %d\n", connectedComponents);
    deleteGraph(graph);
}

