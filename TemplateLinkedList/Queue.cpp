//
// Created by hoben on 3/23/2023.
//

#ifndef TEMPLATELINKEDLIST_QUEUE_CPP
#define TEMPLATELINKEDLIST_QUEUE_CPP

#include "Queue.h"

template<typename T>
Queue<T>::Queue() {
}

template<typename T>
void Queue<T>::push(const T &data) {
    LinkedList<T>::pushBack(data);
}

template<typename T>
void Queue<T>::pop() {
    LinkedList<T>::popFront();
}


template<typename T>
bool Queue<T>::empty() {
    return LinkedList<T>::empty();
}

template<typename T>
int Queue<T>::size() {
    return LinkedList<T>::size();
}

template<typename T>
T &Queue<T>::front() {
    return LinkedList<T>::front();
}

#endif