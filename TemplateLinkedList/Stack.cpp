//
// Created by hoben on 3/23/2023.
//
#ifndef TEMPLATELINKEDLIST_STACK_CPP
#define TEMPLATELINKEDLIST_STACK_CPP
#include "Stack.h"

template<typename T>
void Stack<T>::push(const T &data) {
    LinkedList<T>::pushFront(data);
}

template<typename T>
void Stack<T>::pop() {
    LinkedList<T>::popFront();
}

template<typename T>
bool Stack<T>::empty() {
    return LinkedList<T>::empty();
}

template<typename T>
int Stack<T>::size() {
    return LinkedList<T>::size();
}

template<typename T>
T &Stack<T>::top() {
    return LinkedList<T>::front();
}

template<typename T>
Stack<T>::Stack() {
}

#endif
