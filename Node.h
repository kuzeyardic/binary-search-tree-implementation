/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef Node_h
#define Node_h
#include <stdio.h>

template <class ItemType>
class Node{
public:
    Node();
    Node(const ItemType anItem, Node<ItemType>* nextNodePtr);
    Node(const ItemType anItem);
    ItemType& getItem();
    Node<ItemType>*& getNext();
    void setItem(const ItemType anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    
private:
    ItemType item;
    Node<ItemType>* next;
};
#include "Node.cpp"
#endif /* Node_h */