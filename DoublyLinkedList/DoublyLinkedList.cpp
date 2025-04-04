//
// Created by hoben on 9/26/2023.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_CPP

#include "DoublyLinkedList.h"


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    _nullhead = new Node<T>();
    _null = new Node<T>();
    head = _null;
    tail = _null;
}

template<typename T>
void DoublyLinkedList<T>::addFirstNode(Node<T> *item) {
    head = item;
    tail = item;
    _size++;
    updateNode();
}

template<typename T>
Node<T>* DoublyLinkedList<T>::createNode(const T &item) {
    auto* n = new Node<T>;
    n->next = nullptr;
    n->prev = nullptr;
    n->data = item;
    return n;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T &item) {
    Node<T>* n = createNode(item);
    push_front(n);
}

template<typename T>
void DoublyLinkedList<T>::push_front(Node<T> *item) {
    if(empty())
    {
        addFirstNode(item);
    }
    else
    {
        item->next = head;
        head->prev = item;
        head = item;
        _size ++;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T &item) {
    auto* n = createNode(item);
    push_back(n);
}

template<typename T>
void DoublyLinkedList<T>::push_back(Node<T> *item) {
    if(empty())
    {
        addFirstNode(item);
    }
    else
    {
        tail->next = item;
        item->prev = tail;
        tail = item;
        _size++;
        updateNode();
    }


}

template<typename T>
void DoublyLinkedList<T>::remove(const T &item) {
    auto* tempNode = find(item);
    if(tempNode != nullptr)
    {
        remove(tempNode);
    }
}

template<typename T>
void DoublyLinkedList<T>::remove(Node<T> *item) {
    if(head == tail)
    {
        delete item;
        head = _null;
        tail = _null;
    }
    else if(item == head)
    {
        pop_front();
    }
    else if(item == tail)
    {
        pop_back();
    }
    else
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        delete item;
    }
    _size--;

}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if(empty())
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = tail = _null;
        _size--;
    }
    else {
        Node<T> *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        _size--;
    }

}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    auto *walker = head;
    while (walker->next->next != nullptr) {
        walker = walker->next;
    }
    auto lastNode = walker->next;
    walker->next = nullptr;
    tail = walker;
    delete lastNode;
    _size--;
    updateNode();
}

template<typename T>
void DoublyLinkedList<T>::insertAfter(const T &item, const T &afterThis) {
    auto * n = createNode(item);
    auto * after = find(afterThis);
    insertAfter(n, after);
}

template<typename T>
void DoublyLinkedList<T>::insertAfter(Node<T> *item, Node<T> *afterThis) {
    item->next = afterThis->next;
    afterThis->next = item;
    item->prev = afterThis;
    if(item->next != nullptr)
        item->next->prev = item;
    _size++;
}

template<typename T>
void DoublyLinkedList<T>::insertBefore(const T &item, const T &beforeThis) {
    auto *n = createNode(item);
    auto * before = find(beforeThis);
    insertBefore(n,before);
}

template<typename T>
void DoublyLinkedList<T>::insertBefore(Node<T> *item, Node<T> *beforeThis) {
    item->prev = beforeThis->prev;
    beforeThis->prev = item;
    item->next = beforeThis;
    if(item->prev != nullptr)
        item->prev->next = item;
    else
        head = item;
}
template<typename T>
T &DoublyLinkedList<T>::front() {
    return head->data;
}

template<typename T>
T &DoublyLinkedList<T>::back() {
    return tail->data;
}

template<typename T>
const T &DoublyLinkedList<T>::front() const {
    return head->data;
}

template<typename T>
const T &DoublyLinkedList<T>::back() const {
    return tail->data;
}

template<typename T>
int DoublyLinkedList<T>::size() {
    return _size;
}

template<typename T>
bool DoublyLinkedList<T>::empty() {
    if(_size == 0)
        return true;
    return false;
}

template<typename T>
Node<T> *DoublyLinkedList<T>::find(const T &item) {
    auto * walker = head;
    for(auto it = this->begin(); it!= this->end(); ++it)
    {
        if(*it == item)
            return walker;
        walker = walker->next;
    }
        return nullptr;
}

template<typename S>
std::ostream &operator<<(std::ostream &out, const DoublyLinkedList<S> &list) {
   for(auto it = list.cbegin(); it != list.cend(); ++it)
   {
       out << *it << "---->";
   }
   out <<"nullptr";
   return out;
}

template<typename T>
void DoublyLinkedList<T>::printPrev() {
    std::cout <<"nullptr";
    for (auto it = end(); it!= begin(); --it) {
        std::cout << "<-----" << *it;
    }
}

template<typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &oldObj) {
    if (this != &oldObj ) {
        this->~DoublyLinkedList();
        auto *walker = oldObj.head;
        while (walker != nullptr) {
            push_back(walker->data);
            walker = walker->next;
        }
    }
    return *this;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &a): DoublyLinkedList() {
    *this = a;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while(!empty())
    {
        pop_front();
    }
    delete _null;
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return DoublyLinkedList::iterator(this->head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
        return DoublyLinkedList::iterator(this->tail->next);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::cbegin() const {
    return DoublyLinkedList::const_iterator(this->head);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::cend() const {
    return DoublyLinkedList::const_iterator(this->tail->next);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin() {
    return DoublyLinkedList::reverse_iterator(this->tail);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
    return DoublyLinkedList::reverse_iterator(this->head->prev);
}

template<typename T>
void DoublyLinkedList<T>::updateNode() {
    this->tail->next = this->_null;
    this->_null->prev = this->tail;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while(!empty())
    {
        pop_front();
    }
}

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_CPP