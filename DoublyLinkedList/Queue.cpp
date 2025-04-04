//
// Created by hoben on 10/3/2023.
//
#ifndef DOUBLYLINKEDLIST_QUEUE_CPP
#define DOUBLYLINKEDLIST_QUEUE_CPP

#include "Queue.h"

template<typename T>
void Queue<T>::push(const T &data) {
    this->push_back(data);
}

template<typename T>
void Queue<T>::pop() {
    this->pop_front();
}

template<typename T>
void Queue<T>::print() {
    if(empty())
        return;
    else
    {
        T x = front();
        pop();
        std::cout << x << std::endl;
        print();
        DoublyLinkedList<T>::push_front(x);
    }
}


template<typename T>
Queue<T>::Queue() = default;
#endif