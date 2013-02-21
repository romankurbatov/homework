#include <cstdio>

struct Graph
{
    int numberOfVertices;
    char **edges; //матрица смежности
    bool *visited;
};

Graph *getGraph(const char filename[])
{
    FILE *input = fopen(filename, "r");
    if (input == NULL)
        return NULL;

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

    newGraph->visited = new bool[newGraph->numberOfVertices];
    for (int i = 0; i < newGraph->numberOfVertices; ++i)
        newGraph->visited[i] = false;

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

void dfs(Graph *graph, int vertex)
{
    graph->visited[vertex] = true;
    for (int i = 0; i < graph->numberOfVertices; ++i)
        if (graph->edges[vertex][i] != -1 && !graph->visited[i])
            dfs(graph, i);
}

int countConnectedComponents(Graph *graph)
{
    if (graph == NULL)
        return 0;
    for (int i = 0; i < graph->numberOfVertices; ++i)
        graph->visited[i] = false;
    int connectedComponents = 0;
    for (int i = 0; i < graph->numberOfVertices; ++i)
        if (!graph->visited[i])
        {
            ++connectedComponents;
            dfs(graph, i);
        }
    return connectedComponents;
}

void deleteGraph(Graph *graph)
{
    if (graph == NULL)
        return;
    for (int i = 0; i < graph->numberOfVertices; ++i)
        delete[] graph->edges[i];
    delete[] graph->edges;
    delete[] graph->visited;
    delete graph;
}
