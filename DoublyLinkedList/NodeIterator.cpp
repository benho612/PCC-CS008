//
// Created by hoben on 10/3/2023.
//

#ifndef DOUBLYLINKEDLIST_NODEITERATOR_cpp
#define DOUBLYLINKEDLIST_NODEITERATOR_cpp

#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator() = default;

template<typename T>
NodeIterator<T>::NodeIterator(Node<T>* current):current(current){
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int) {
    NodeIterator<T> iter = *this;
    ++iter;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++() {
    if(this->current)
         current = current->next;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int) {
    NodeIterator<T> iter = * this;
    --iter;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--() {
    if(this->current)
        return current = current->prev;
    return *this;
}

template<typename T>
T &NodeIterator<T>::operator*() {
    return current->data;
}

template<typename S>
bool operator!=(const NodeIterator<S> &rhs,const NodeIterator<S> &lhs) {
    return rhs.current != lhs.current;
}


template<typename S>
bool operator==(const NodeIterator<S> &rhs, const NodeIterator<S> &lhs) {
    return rhs.current == lhs.current;
}


#endif
