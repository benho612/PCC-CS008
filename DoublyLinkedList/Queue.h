//
// Created by hoben on 10/3/2023.
//

#ifndef DOUBLYLINKEDLIST_QUEUE_H
#define DOUBLYLINKEDLIST_QUEUE_H
#include "DoublyLinkedList.h"
template<typename T>
class Queue:private DoublyLinkedList<T> {
public:
    Queue();
    void push(const T& data);
    void pop();
    void print();
    using DoublyLinkedList<T>::front;
    using DoublyLinkedList<T>::empty;
private:
};



#include "Queue.cpp"
#endif //DOUBLYLINKEDLIST_QUEUE_H
