#pragma once

struct ParseTree;

ParseTree *getParseTree(FILE *file);
double calculate(ParseTree *tree);
void printParseTree(ParseTree *tree);
void deleteParseTree(ParseTree *tree);
