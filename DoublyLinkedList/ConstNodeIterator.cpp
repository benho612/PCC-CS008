//
// Created by hoben on 10/3/2023.
//

#ifndef DOUBLYLINKEDLIST_CONSTNODEITERATOR_cpp
#define DOUBLYLINKEDLIST_CONSTNODEITERATOR_cpp

#include "ConstNodeIterator.h"

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator() = default;

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator(Node<T>* current):current(current){
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator++(int) {
    ConstNodeIterator<T> iter = *this;
    ++iter;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator++() {
    if(this->current)
         current = current->next;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator--(int) {
    ConstNodeIterator<T> iter = * this;
    --iter;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator--() {
    if(this->current)
        return current = current->prev;
    return *this;
}

template<typename T>
const T &ConstNodeIterator<T>::operator*() const {
    return current->data;
}

template<typename S>
bool operator!=(const ConstNodeIterator<S> &rhs, const ConstNodeIterator<S> &lhs) {
    return rhs.current != lhs.current;
}


template<typename S>
bool operator==(const ConstNodeIterator<S> &rhs, const ConstNodeIterator<S> &lhs) {
    return rhs.current == lhs.current;
}


#endif
