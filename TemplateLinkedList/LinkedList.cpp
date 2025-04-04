//
// Created by hoben on 3/16/2023.
//
#ifndef LINKEDLISTPROJECT_LINKEDLIST_CPP
#define LINKEDLISTPROJECT_LINKEDLIST_CPP

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    //addFirstNode(0);
}


template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *walker = this->head;
    for(int i = 0; i<_size;i++)
    {
        if(walker->next != nullptr)
        {
            walker = walker->next;
            delete head;
            head = walker;
        }
    }
    delete tail;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &a):LinkedList() {
    //*this = a;
    operator=(a);
}



template<typename T>
void LinkedList<T>::pushFront(const T& data) {
    auto* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    if(this->tail == nullptr)
        this->tail = this->head;
}

template<typename T>
void LinkedList<T>::pushBack(const T& data) {
    if(this->head != nullptr)
    {
        auto* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        Node<T>* walker = this->head;
        while(walker->next != nullptr)
        {
            walker = walker->next;
        }
        walker->next = newNode;
        tail = newNode;
    }
    else
    {
        pushFront(data);
    }
}

template<typename T>
void LinkedList<T>::insertBefore(const T source, const T target) {
    auto *n = new Node<T>;
    n->data = source;
    Node<T> *walker = this->head;
    while (walker->next->data != target && walker->next != nullptr) {
        walker = walker->next;
    }
    n->next = walker->next;
    walker->next = n;
}

template<typename T>
void LinkedList<T>::insertAfter(const T source, const T target) {
    auto *n = new Node<T>;
    n->data = source;
    Node<T> *walker = this->head;
    while (walker->next->data != target && walker->next != nullptr) {
        walker = walker->next;
    }
    walker= walker->next;
    n->next = walker->next;
    walker->next = n;

}

template<typename T>
void LinkedList<T>::remove(const T& data) {
    Node<T>* walker = this->head;
    while(walker->next->data != data)
    {
        walker = walker->next;
    }
    walker->next = walker->next->next;
}

template<typename T>
int LinkedList<T>::size() {
    Node<T> *walker = this->head;
    while(walker != nullptr)
    {
        _size ++;
        walker = walker->next;
    }
    return _size;
}

template<typename T>
bool LinkedList<T>::empty() {
    if(head == nullptr)
        return true;
    return false;

}

template<typename T>
T &LinkedList<T>::front() {
    return head->data;
}

template<typename T>
T &LinkedList<T>::back() {
    return tail->data;
}

template<typename T>
void LinkedList<T>::popFront() {
    head = head->next;
}

template<typename T>
void LinkedList<T>::popBack() {
    Node<T> *walker = this->head;
    while (walker->next->next != nullptr) {
        walker = walker->next;
    }
    walker->next = nullptr;
    tail = walker;
}

template<typename T>
Node<T> *LinkedList<T>::search(const T data) {
    Node<T> *walker = this->head;
    while (walker->next->data != data && walker->next != nullptr) {
        walker = walker->next;
    }
    return *walker;
}

template<typename T>
void LinkedList<T>::addFirstNode(const T& data) {
    auto* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

template<typename S>
std::ostream &operator<<(std::ostream &out, const LinkedList<S> &list) {
    Node<S>* walker;
    walker = list.head;
    while(walker != nullptr)
    {
        std::cout << walker->data << "--->";
        walker = walker->next;
    }
    std::cout<< "nullptr";
    return out;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &oldObj) {
    if (&oldObj != this) {
        Node<T> *walker = oldObj.head;
        this->~LinkedList();
        while (walker != nullptr) {
            pushBack(walker->data);
            walker = walker->next;
        }
    }
    return *this;
}


#endif //LINKEDLISTPROJECT_LINKEDLIST_CPP
