/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef Queue_cpp
#define Queue_cpp
#include "Queue.h"

template <class ItemType>
Queue<ItemType>::Queue(){
    frontPtr=nullptr;
    backPtr = nullptr;
    itemCount=0;
}


template <class ItemType>
Queue<ItemType>::~Queue(){
    while(itemCount!=0){
        pop();
    }
}

template <class ItemType>
bool Queue<ItemType>::push(const ItemType& newItem){
    
    Node<ItemType>* temp = new Node<ItemType>(newItem);
    if (itemCount == 0) {
        frontPtr = temp;
        backPtr = temp;

    } else {
        backPtr->setNext(temp);
        backPtr = temp;
    }

    itemCount++;
    return true;
}

template <class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue){

    Node<ItemType>* origChainPtr = aQueue.frontPtr;  
    itemCount = aQueue.itemCount;
    if (origChainPtr == nullptr) {
        frontPtr = nullptr;  
    } else {
        frontPtr = new Node<ItemType>(origChainPtr->getItem());
        Node<ItemType>* newChainPtr = frontPtr;      
        origChainPtr = origChainPtr->getNext();    
        while (origChainPtr != nullptr) {
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); 
    }
}

template <class ItemType>
Queue<ItemType>& Queue<ItemType>::operator=(const Queue<ItemType>& rightHandSide){
    
        while(itemCount>0){
            pop();
        }
        Node<ItemType>* origChainPtr = rightHandSide.frontPtr;  
        if (origChainPtr == nullptr) {
            frontPtr = nullptr;  
        } else {
            frontPtr = new Node<ItemType>(origChainPtr->getItem());
            Node<ItemType>* newChainPtr = frontPtr;      
            origChainPtr = origChainPtr->getNext();    
            while (origChainPtr != nullptr) {
                ItemType nextItem = origChainPtr->getItem();
                Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
                newChainPtr->setNext(newNodePtr);
                newChainPtr = newChainPtr->getNext();
                origChainPtr = origChainPtr->getNext();
            }
            newChainPtr->setNext(nullptr); 
        }
    
        itemCount = rightHandSide.itemCount;

    return *this;
}



template <class ItemType>
bool Queue<ItemType>::pop(){
    if (itemCount == 0) {
        return false;
    } else {
        Node<ItemType>* temp = frontPtr;
        frontPtr = frontPtr->getNext();
        delete temp;
        itemCount--;
        return true;
    }
}

template <class ItemType>
int Queue<ItemType>::size(){
    return itemCount;
}


template <class ItemType>
ItemType Queue<ItemType>::front() const {
        if(itemCount==0){
        throw std::runtime_error("Attempted to access the top of an empty queue.");
            }
        else{
            return frontPtr->getItem();
        }
   
}







#endif

