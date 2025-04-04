//
// Created by hoben on 10/2/2023.
//

#ifndef DOUBLYLINKEDLIST_STACK_H
#define DOUBLYLINKEDLIST_STACK_H

#include "DoublyLinkedList.h"

template <typename T>
class Stack {
public:
    Stack();
    T& top();
    void push(const T& data);
    void pop();
    void print();
    bool empty();
private:
    DoublyLinkedList<T> list;
    //using DoublyLinkedList<T>::insertAfter; ///"using" keyword hiding the function
};



#include "Stack.cpp"

#endif //DOUBLYLINKEDLIST_STACK_H
