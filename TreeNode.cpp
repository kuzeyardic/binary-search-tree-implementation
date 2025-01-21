/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#include "TreeNode.h"

TreeNode::TreeNode(){
    item = 0;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

TreeNode::TreeNode( int anItem, 
TreeNode* leftChild, 
TreeNode* rightChild ){
    item = anItem;
    leftChildPtr = leftChild;
    rightChildPtr = rightChild;
}


