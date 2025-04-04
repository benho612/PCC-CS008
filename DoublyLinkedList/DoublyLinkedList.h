//
// Created by hoben on 9/26/2023.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#include "Node.h"
#include <iostream>
#include "NodeIterator.h"
#include "ConstNodeIterator.h"
#include "ReverseIterator.h"
template <typename T>
class DoublyLinkedList {
private:
    Node<T>*head;
    Node<T>*tail;
    Node<T>* _null = nullptr;
    Node<T>* _nullhead = nullptr;
    int _size = 0;
    Node<T>* createNode(const T& item);
    void addFirstNode(Node<T>* item);
    void push_front(Node<T>* item); /// add item to the front of the list
    void push_back(Node<T>* item); /// add item to the last of the list
    void remove(Node<T>* item); /// remove item in the list
    void insertAfter(Node<T>* item, Node<T>* afterThis); /// insert the item after this node.
    void insertBefore(Node<T>* item, Node<T>* beforeThis);
    Node<T>* find(const T& item);
    void updateNode();
public:
    void clear();
    bool empty();
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& a);
    void push_front(const T& item); /// add item to the front of the list
    void push_back(const T& item); /// add item to the last of the list
    void remove(const T& item); /// remove item in the list
    void pop_front(); ///remove first node in the list
    void pop_back(); ///remove last node in the list
    void insertAfter(const T& item, const T& afterThis); /// insert the item after this node.
    void insertBefore(const T& item, const T& beforeThis); ///insert the item before this node.
    T& front(); /// return the first item in the list
    T& back(); ///return the last item in the list
    const T& front() const;
    const T& back() const;
    int size();
    void printPrev();

    template<typename S>
    friend std::ostream& operator <<(std::ostream& out, const DoublyLinkedList<S>& list);

    DoublyLinkedList<T> & operator =(const DoublyLinkedList<T> &oldObj);

    typedef NodeIterator<T> iterator;
    typedef ConstNodeIterator<T> const_iterator;
    typedef ReverseIterator<T> reverse_iterator;
    iterator begin();
    const_iterator cbegin() const ;
    iterator end();
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();

};



#include "DoublyLinkedList.cpp"

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
