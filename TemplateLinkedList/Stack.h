//
// Created by hoben on 3/23/2023.
//

#ifndef TEMPLATELINKEDLIST_STACK_H
#define TEMPLATELINKEDLIST_STACK_H

#include "Node.h"
#include "LinkedList.h"

template <typename T>
class Stack:public LinkedList<T> {
public:
    Stack();
    void push(const T& data);
    void pop();
    bool empty();
    int size();
    T& top();
};




#include "Stack.cpp"
#endif //TEMPLATELINKEDLIST_STACK_H
