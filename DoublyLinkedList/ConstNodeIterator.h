//
// Created by hoben on 10/3/2023.
//

#ifndef DOUBLYLINKEDLIST_CONSTNODEITERATOR_H
#define DOUBLYLINKEDLIST_CONSTNODEITERATOR_H
#include "Node.h"
#include <iterator>
template <typename T>
class ConstNodeIterator: public std::iterator<std::bidirectional_iterator_tag,T> {
private:
    Node<T>* current;
public:

    ConstNodeIterator();

    ConstNodeIterator(Node<T>* current); // one line

    ConstNodeIterator<T> operator ++(int); // two line
    //postfix ++ operator
    ConstNodeIterator<T> operator ++(); //two lines / one lines
    //prefix
    ConstNodeIterator<T> operator --(int); //two lines
    //postfix -- operator
    ConstNodeIterator<T> operator --(); //two or one lines
    //prefix


    const T& operator*() const;

    template <typename S>
    friend bool operator !=(const ConstNodeIterator<S>& rhs, const ConstNodeIterator<S>& lhs);

    template <typename S>
    friend bool operator ==(const ConstNodeIterator<S>& rhs, const ConstNodeIterator<S>& lhs);

};



#include "ConstNodeIterator.cpp"

#endif //DOUBLYLINKEDLIST_CONSTNODEITERATOR_H
