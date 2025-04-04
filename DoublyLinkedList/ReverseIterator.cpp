//
// Created by hoben on 10/10/2023.
//

#include "ReverseIterator.h"

template<typename T>
ReverseIterator<T>::ReverseIterator() = default;

template<typename T>
ReverseIterator<T>::ReverseIterator(Node<T> *current):current(current) {
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int) {
    ReverseIterator<T> iter = *this;
    current = current->prev;
    return *this;
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator++() {
    current = current -> prev;
    return * this;
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator--(int) {
    ReverseIterator<T> iter = *this;
    current = current->next;
    return *this;
}

template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator--() {
    current = current ->next;
    return * this;
}

template<typename T>
const T &ReverseIterator<T>::operator*() const {
    return current->data;
}

template<typename S>
bool operator!=(const ReverseIterator<S> &rhs, const ReverseIterator<S> &lhs) {
    return rhs.current != lhs.current;
}


template<typename S>
bool operator==(const ReverseIterator<S> &rhs, const ReverseIterator<S> &lhs) {
    return rhs.current != lhs.current;
}