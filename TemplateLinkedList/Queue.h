//
// Created by hoben on 3/23/2023.
//

#ifndef TEMPLATELINKEDLIST_QUEUE_H
#define TEMPLATELINKEDLIST_QUEUE_H

#include "Node.h"
#include "LinkedList.h"
template<typename T>
class Queue:public LinkedList<T> {
public:
    Queue();
    void push(const T& data);
    void pop();
    bool empty();
    int size();
    T& front();
};




#include "Queue.cpp"
#endif //TEMPLATELINKEDLIST_QUEUE_H
