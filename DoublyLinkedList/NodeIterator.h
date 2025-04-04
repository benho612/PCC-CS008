//
// Created by hoben on 10/3/2023.
//

#ifndef DOUBLYLINKEDLIST_NODEITERATOR_H
#define DOUBLYLINKEDLIST_NODEITERATOR_H
#include "Node.h"
#include <iterator>
template <typename T>
class NodeIterator: public std::iterator<std::bidirectional_iterator_tag,T> {
private:
    Node<T>* current;
public:

    NodeIterator();

    NodeIterator(Node<T>* current); // one line

    NodeIterator<T> operator ++(int); // two line
    //postfix ++ operator
    NodeIterator<T> operator ++(); //two lines / one lines
    //prefix
    NodeIterator<T> operator --(int); //two lines
    //postfix -- operator
    NodeIterator<T> operator --(); //two or one lines
    //prefix

    T& operator *(); //one lines

    template <typename S>
    friend bool operator !=(const NodeIterator<S>& rhs, const NodeIterator<S>& lhs);

    template <typename S>
    friend bool operator ==(const NodeIterator<S>& rhs, const NodeIterator<S>& lhs);

};



#include "NodeIterator.cpp"

#endif //DOUBLYLINKEDLIST_NODEITERATOR_H
