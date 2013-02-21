#include <cstdio>

enum ValueType { operation, number };

struct ParseTreeNode
{
    ValueType type;
    union
    {
        char operation;
        int number;
    };
    ParseTreeNode *leftChild;
    ParseTreeNode *rightChild;
};

struct ParseTree
{
    ParseTreeNode *root;
};

void getParseTree(FILE *file, ParseTreeNode *&node);

void getOperand(FILE *file, ParseTreeNode *&node)
{
    int c = EOF;

    do
    {
        c = fgetc(file);
    }
    while (c == ' ');


    if (c == '(')
    {
        ungetc(c, file);
        getParseTree(file, node);
    }
    else
    {
        ungetc(c, file);
        node = new ParseTreeNode;
        node->type = number;
        node->number = 0;
        node->leftChild = NULL;
        node->rightChild = NULL;
        fscanf(file, "%d", &node->number);
    }
}

void getParseTree(FILE *file, ParseTreeNode *&node)
{
    node = new ParseTreeNode;
    node->type = operation;
    node->leftChild = NULL;
    node->rightChild = NULL;
    fgetc(file); //считываем "("
    node->operation = fgetc(file); //считываем знак операции

    getOperand(file, node->leftChild);
    getOperand(file, node->rightChild);

    fgetc(file); //считываем ")"
}

ParseTree *getParseTree(FILE *file)
{
    ParseTree *tree = new ParseTree;
    getParseTree(file, tree->root);
    return tree;
}

double calculate(ParseTreeNode *node)
{
    if (node->type == number)
        return node->number;
    else
    {
        double operand1 = calculate(node->leftChild);
        double operand2 = calculate(node->rightChild);
        switch (node->operation)
        {
            case '+':
            {
                return operand1 + operand2;
            }
            case '-':
            {
                return operand1 - operand2;
            }
            case '*':
            {
                return operand1 * operand2;
            }
            case '/':
            {
                return operand1 / operand2;
            }
        }
    }
}

double calculate(ParseTree *tree)
{
    return calculate(tree->root);
}

void printParseTree(ParseTreeNode *node)
{
    if (node->type == number)
    {
        printf("%d", node->number);
        return;
    }
    printf("(%c ", node->operation);
    printParseTree(node->leftChild);
    putchar(' ');
    printParseTree(node->rightChild);
    putchar(')');
}

void printParseTree(ParseTree *tree)
{
    printParseTree(tree->root);
}

void deleteParseTreeNode(ParseTreeNode *node)
{
    if (node == NULL)
        return;
    deleteParseTreeNode(node->leftChild);
    deleteParseTreeNode(node->rightChild);
    delete node;
}

void deleteParseTree(ParseTree *tree)
{
    deleteParseTreeNode(tree->root);
    delete tree;
}
