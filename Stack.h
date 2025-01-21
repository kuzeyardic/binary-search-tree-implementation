/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef Stack_h
#define Stack_h
#include "Node.h"
#include <stdio.h>
#include <iostream>
template <class ItemType>
class Stack {
    
    
public:
    Stack();
   ~Stack();
    Stack(const Stack<ItemType>& aStack);
    Stack<ItemType>& operator=(const Stack<ItemType>& rightHandSide);
    bool push(const ItemType& newItem);
    bool pop();
    int size();
    ItemType top() const;
private:
    Node<ItemType>* topPtr;
    int itemCount;
};
#include "Stack.cpp"
#endif /* Stack_h */
