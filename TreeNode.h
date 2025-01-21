/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef TreeNode_h
#define TreeNode_h
#include <stdio.h>

class TreeNode{
public:
    TreeNode();
    TreeNode( int anItem, TreeNode* leftChild, TreeNode* rightChild );
    int item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr; 
};
#endif /* TreeNode_h */
