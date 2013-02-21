#include <cstdio>

struct Graph
{
    int numberOfVertices;
    char **edges; //матрица смежности
};

Graph *getGraph(const char filename[])
{
    FILE *input = fopen(filename, "r");
    Graph *newGraph = new Graph;

    newGraph->numberOfVertices = 0;
    fscanf(input, "%d", &newGraph->numberOfVertices);

    newGraph->edges = new char*[newGraph->numberOfVertices];
    for (int i = 0; i < newGraph->numberOfVertices; ++i)
    {
        newGraph->edges[i] = new char[newGraph->numberOfVertices];
        for (int j = 0; j < newGraph->numberOfVertices; ++j)
            newGraph->edges[i][j] = -1;
    }

    int numberOfEdges = 0;
    fscanf(input, "%d", &numberOfEdges);

    int from = 0;
    int to = 0;
    int length = 0;
    for (int i = 0; i < numberOfEdges; ++i)
    {
        fscanf(input, "%d %d %d", &from, &to, &length);
        newGraph->edges[from - 1][to - 1] = length;
        newGraph->edges[to - 1][from - 1] = length;
    }

    fclose(input);
    return newGraph;
}

int findClosestVertex(Graph *graph, bool *visited, int *distance)
{
    int minDistance = -1;
    int closestVertex = 0;
    for (int i = 0; i < graph->numberOfVertices; ++i)
    {
        if (!visited[i] && distance[i] != -1)
            if (minDistance == -1 || distance[i] < minDistance)
            {
                minDistance = distance[i];
                closestVertex = i;
            }
    }
    return closestVertex;
}

void findShortestWays(Graph *graph, int *distance, char *route)
{
    distance[0] = 0;
    for (int i = 1; i < graph->numberOfVertices; ++i)
        distance[i] = -1;
    for (int i = 0; i < graph->numberOfVertices; ++i)
        route[i] = -1;

    bool *visited = new bool[graph->numberOfVertices];
    for (int i = 0; i < graph->numberOfVertices; ++i)
        visited[i] = false;

    for (int i = 0; i < graph->numberOfVertices; ++i)
    {
        int vertex = findClosestVertex(graph, visited, distance);
        visited[vertex] = true;
        for (int j = 0; j < graph->numberOfVertices; ++j)
            if (!visited[j] && graph->edges[vertex][j] != -1)
            {
                int newDistance = distance[vertex] + graph->edges[vertex][j];
                if (distance[j] == -1 || distance[j] > newDistance)
                {
                    distance[j] = newDistance;
                    route[j] = vertex;
                }
            }
    }
    delete[] visited;
}

void swap(int& a, int& b)
{
    if (a == b)
        return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void quickSort(int number[], int value[], int first, int last)
{
    if (first >= last)
        return;
    swap(value[first], value[(first + last) / 2]);
    swap(number[first], number[(first + last) / 2]);
    int lastOfTheFirstPart = first;
    for (int i = first + 1; i <= last; i++)
        if (value[i] < value[first]) {
            lastOfTheFirstPart++;
            swap(value[i], value[lastOfTheFirstPart]);
            swap(number[i], number[lastOfTheFirstPart]);
        }
    swap(value[first], value[lastOfTheFirstPart]);
    swap(number[first], number[lastOfTheFirstPart]);
    quickSort(number, value, 0, lastOfTheFirstPart - 1);
    quickSort(number, value, lastOfTheFirstPart + 1, last);
}

void printRoute(char *route, int n)
{
    if (n != 0)
        printRoute(route, route[n]);
    printf("%d ", n + 1);
}

void printWays(Graph *graph, int *distance, char *route)
{
    //Сортируем массив расстояний до вершин distance.
    //При этом, чтобы знать, какой элемент массива distance какой вершине соответствует,
    //создаем новый массив vertexNumber. В нём на i-й позиции стоит номер вершины,
    //которой соответствует i-й элемент массива distance. Каждый раз, когда при сортировке меняем
    //местами элементы массива distance, меняем также соответствующие элементы массива vertexNumber.
    //Для этого используем модифицированный вариант алгоритма быстрой сортировки.
    int *vertexNumber = new int[graph->numberOfVertices];
    for (int i = 0; i < graph->numberOfVertices; ++i)
        vertexNumber[i] = i;
    quickSort(vertexNumber, distance, 0, graph->numberOfVertices - 1);

    printf("Города будут захвачены в следующем порядке:\n");
    for (int i = 1; i < graph->numberOfVertices; ++i)
    {
        printf("Город %d\n", vertexNumber[i] + 1);
        printf("Расстояние до города 1: %d\n", distance[i]);
        printf("Кратчайший путь из 1 в %d: ", vertexNumber[i] + 1);
        printRoute(route, vertexNumber[i]);
        printf("\n\n");
    }
    delete[] vertexNumber;
}

void deleteGraph(Graph *graph)
{
    for (int i = 0; i < graph->numberOfVertices; ++i)
        delete[] graph->edges[i];
    delete[] graph->edges;
    delete graph;
    graph = NULL;
}

int main()
{
    Graph *graph = getGraph("input.txt");

    int *distance = new int[graph->numberOfVertices];
    char *route = new char[graph->numberOfVertices];
    findShortestWays(graph, distance, route);
    printWays(graph, distance, route);
    delete[] distance;
    delete[] route;
    deleteGraph(graph);
}

