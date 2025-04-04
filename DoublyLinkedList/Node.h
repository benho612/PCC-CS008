//
// Created by hoben on 9/26/2023.
//

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H
template <typename T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

#endif //DOUBLYLINKEDLIST_NODE_H
