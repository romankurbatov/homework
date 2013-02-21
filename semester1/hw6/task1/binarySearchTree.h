#pragma once

struct BinarySearchTree;

BinarySearchTree *createBinarySearchTree();
void addToBinarySearchTree(BinarySearchTree *tree, int value);
bool existsInBinarySearchTree(BinarySearchTree *tree, int value);
void removeFromBinarySearchTree(BinarySearchTree *tree, int value);
void printLowToHigh(BinarySearchTree *tree);
void printHighToLow(BinarySearchTree *tree);
void deleteBinarySearchTree(BinarySearchTree *tree);
