#include <cstdio>

struct BinarySearchTreeNode
{
    int value;
    BinarySearchTreeNode *leftChild;
    BinarySearchTreeNode *rightChild;
};

struct BinarySearchTree
{
    BinarySearchTreeNode *root;
};

BinarySearchTree *createBinarySearchTree()
{
    BinarySearchTree *newTree = new BinarySearchTree;
    newTree->root = NULL;
    return newTree;
}

BinarySearchTreeNode *createBinarySearchTreeNode(int value)
{
    BinarySearchTreeNode *newNode = new BinarySearchTreeNode;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void addToBinarySearchTree(BinarySearchTreeNode *&node, int value)
{
    if (node == NULL)
        node = createBinarySearchTreeNode(value);
    else if (node->value > value)
        addToBinarySearchTree(node->leftChild, value);
    else if (node->value < value)
        addToBinarySearchTree(node->rightChild, value);
}

void addToBinarySearchTree(BinarySearchTree *tree, int value)
{
    addToBinarySearchTree(tree->root, value);
}

bool existsInBinarySearchTree(BinarySearchTree *tree, int value)
{
    if (tree->root == NULL)
        return false;
    BinarySearchTreeNode *currentNode = tree->root;
    while (true)
    {
        if (currentNode == NULL)
            return false;
        if (value > currentNode->value)
            currentNode = currentNode->rightChild;
        else if (value < currentNode->value)
            currentNode = currentNode->leftChild;
        else
            return true;
    }
}

int leftmostChild(BinarySearchTreeNode *node)
{
    if (node->leftChild == NULL)
        return node->value;
    else
        return leftmostChild(node->leftChild);
}

void removeFromBinarySearchTree(BinarySearchTreeNode *&node, int value)
{
    if (node == NULL)
        return;
    else if (node->value > value)
        removeFromBinarySearchTree(node->leftChild, value);
    else if (node->value < value)
        removeFromBinarySearchTree(node->rightChild, value);
    else
    {
        if (node->leftChild == NULL)
        {
            BinarySearchTreeNode *rightChild = node->rightChild;
            delete node;
            node = rightChild;
        }
        else if (node->rightChild == NULL)
        {
            BinarySearchTreeNode *leftChild = node->leftChild;
            delete node;
            node = leftChild;
        }
        else
        {
            node->value = leftmostChild(node->rightChild);
            removeFromBinarySearchTree(node->rightChild, node->value);
        }
    }
}

void removeFromBinarySearchTree(BinarySearchTree *tree, int value)
{
    removeFromBinarySearchTree(tree->root, value);
}

void printLowToHigh(BinarySearchTreeNode *node)
{
    if (node == NULL)
        return;
    printLowToHigh(node->leftChild);
    printf("%d ", node->value);
    printLowToHigh(node->rightChild);
}

void printLowToHigh(BinarySearchTree *tree)
{
    printLowToHigh(tree->root);
    putchar('\n');
}

void printHighToLow(BinarySearchTreeNode *node)
{
    if (node == NULL)
        return;
    printHighToLow(node->rightChild);
    printf("%d ", node->value);
    printHighToLow(node->leftChild);
}

void printHighToLow(BinarySearchTree *tree)
{
    printHighToLow(tree->root);
    putchar('\n');
}

void deleteBinarySearchTree(BinarySearchTreeNode *node)
{
    if (node == NULL)
        return;
    deleteBinarySearchTree(node->leftChild);
    deleteBinarySearchTree(node->rightChild);
    delete node;
}

void deleteBinarySearchTree(BinarySearchTree *tree)
{
    deleteBinarySearchTree(tree->root);
    delete tree;
}
