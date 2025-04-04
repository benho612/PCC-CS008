//
// Created by hoben on 10/2/2023.
//
#ifndef DOUBLYLINKEDLIST_STACK_CPP
#define DOUBLYLINKEDLIST_STACK_CPP
#include "Stack.h"

template<typename T>
T& Stack<T>::top() {
    return list.front();
}

template<typename T>
void Stack<T>::push(const T& data) {
    list.push_front(data);
}

template<typename T>
void Stack<T>::pop() {
    list.pop_front();
}
///using recursive functions keeps the values there until the call is finished.
template<typename T>
void Stack<T>::print() {
   if(empty())
       return;
   else
   {
       T x = top();
       pop();
       std::cout << x << std::endl;
       print();
       push(x);
   }

}

template<typename T>
Stack<T>::Stack() = default;

template<typename T>
bool Stack<T>::empty() {
    if (list.empty())
        return true;
    return false;
}


#endif //DOUBLYLINKEDLIST_STACK_CPP
