/**
* Title: Binary Search Trees
* Author : Berke Kuzey Ardıç
* ID : 22103340
* Section : 001
* Homework : 01
*/
#ifndef Stack_cpp
#define Stack_cpp
#include "Stack.h"

template <class ItemType>
Stack<ItemType>::Stack(){
    topPtr=nullptr;
    itemCount=0;
}

template <class ItemType>
Stack<ItemType>::~Stack(){
    while(itemCount>0){
        pop();
    }
}

template <class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& aStack) {

     Node<ItemType>* origChainPtr = aStack.topPtr;  
     itemCount = aStack.itemCount;

    if (origChainPtr == nullptr) {
        topPtr = nullptr;  
    } else {
        topPtr = new Node<ItemType>(origChainPtr->getItem());
       
        Node<ItemType>* newChainPtr = topPtr;      
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
Stack<ItemType>& Stack<ItemType>::operator=(const Stack<ItemType>& rightHandSide){

        while(itemCount>0){
            pop();
        }
        Node<ItemType>* origChainPtr = rightHandSide.topPtr;  

        if (origChainPtr == nullptr) {
            topPtr = nullptr;  
        } else {
            topPtr = new Node<ItemType>(origChainPtr->getItem());
            Node<ItemType>* newChainPtr = topPtr;      
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
bool Stack<ItemType>::push(const ItemType& newItem){
    Node<ItemType>* temp = new Node<ItemType>(newItem);
    temp->setNext(topPtr);
    topPtr = temp;
    temp = nullptr;
    itemCount++;
    return true;
}
template <class ItemType>
bool Stack<ItemType>::pop(){
    if(itemCount==0){
        return false;
    }else{
        Node<ItemType>* temp = topPtr;
        topPtr = topPtr->getNext();
        delete temp;
        itemCount--;
        return true;
    }
}

template <class ItemType>
int Stack<ItemType>::size(){
    return itemCount;
}


template <class ItemType>
ItemType Stack<ItemType>::top() const {
          if(itemCount==0){
        throw std::runtime_error("Attempted to access the top of an empty stack.");
            }
        else{
            return topPtr->getItem();
        }
    
}
#endif

