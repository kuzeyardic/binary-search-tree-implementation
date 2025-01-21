/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef BST_H
#define BST_H
#include "TreeNode.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class BST {
public:
    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    void pathFromAtoB(int A, int B);
    int heightOfThetree();
    void insertKeyWithoutPrint(int key);

private:
    int  findHeight(TreeNode* treePtr);
    void insertItem(TreeNode*& treePtr, int itemKey, bool org);
    void deleteItem(TreeNode*& treePtr, int itemKey, bool org);
    void destroyTree(TreeNode*& treePtr);
    void inorder(TreeNode* treePtr);
    int findFullBTLevel(TreeNode* treePtr);
    void maximumSumPath(TreeNode* treePtr, int sum, int& maxSum, Stack<TreeNode*>& nodes, Stack< Stack<TreeNode*> >& paths);
    int findBiggestElement();
    int findSmallestElement(TreeNode* treePtr);
    TreeNode* lowestCommonAncestorFinder(int A, int B, TreeNode* treePtr);
    void findPathFromAtoB(int A, TreeNode* treePtr, Stack<TreeNode*>& nodes);
    TreeNode *root;
};
#endif
