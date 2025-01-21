/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef Queue_h
#define Queue_h
#include "Node.h"
#include <stdio.h>
#include <iostream>
template <class ItemType>
class Queue {
      
public:
    Queue();
   ~Queue();
    Queue(const Queue<ItemType>& aQueue);
    Queue<ItemType>& operator=(const Queue<ItemType>& rightHandSide);
    bool push(const ItemType& newItem);
    bool pop();
    int size();
    ItemType front() const;
private:
    Node<ItemType>* frontPtr;
    Node<ItemType>* backPtr;
    int itemCount;
};
#include "Queue.cpp"
#endif /* Queue_h */