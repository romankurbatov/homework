#pragma once

struct Graph;

Graph *getGraph(const char filename[]);
int countConnectedComponents(Graph *graph);
void deleteGraph(Graph *graph);
