//
// Created by hoben on 10/10/2023.
//

#ifndef DOUBLYLINKEDLIST_REVERSEITERATOR_H
#define DOUBLYLINKEDLIST_REVERSEITERATOR_H

#include <iostream>
#include "Node.h"
template <typename T>
class ReverseIterator: public std::iterator<std::bidirectional_iterator_tag,T> {
private:
    Node<T>* current;
public:

    ReverseIterator();

    ReverseIterator(Node<T>* current); // one line

    ReverseIterator<T> operator ++(int); // two line
    //postfix ++ operator
    ReverseIterator<T> operator ++(); //two lines / one lines
    //prefix
    ReverseIterator<T> operator --(int); //two lines
    //postfix -- operator
    ReverseIterator<T> operator --(); //two or one lines
    //prefix


    const T& operator*() const;

    template <typename S>
    friend bool operator !=(const ReverseIterator<S>& rhs, const ReverseIterator<S>& lhs);

    template <typename S>
    friend bool operator ==(const ReverseIterator<S>& rhs, const ReverseIterator<S>& lhs);

};




#endif //DOUBLYLINKEDLIST_REVERSEITERATOR_H
