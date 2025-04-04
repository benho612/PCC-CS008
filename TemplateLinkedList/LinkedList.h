//
// Created by hoben on 3/16/2023.
//

#ifndef LINKEDLISTPROJECT_LINKEDLIST_H
#define LINKEDLISTPROJECT_LINKEDLIST_H
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList {
private:
    Node<T>*head, *tail;
    int _size = 0;
    Node<T>* search(const T data);
    void addFirstNode(const T& data);
public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList<T>& a);
    void pushFront(const T& data);
    void pushBack(const T& data);
    void remove(const T& data);
    void insertBefore(const T source, const T target);
    void insertAfter(const T source, const T target);
    void popFront();
    void popBack();
    T& front();
    T& back();
    int size();
    bool empty();

    template<typename S>
    friend std::ostream& operator <<(std::ostream& out, const LinkedList<S>& list);

    LinkedList<T> & operator =(const LinkedList<T> &oldObj);


};


#include "LinkedList.cpp"
#endif //LINKEDLISTPROJECT_LINKEDLIST_H
