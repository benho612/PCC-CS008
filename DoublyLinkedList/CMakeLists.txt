cmake_minimum_required(VERSION 3.24)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoublyLinkedList main.cpp DoublyLinkedList.cpp DoublyLinkedList.h Node.h Stack.cpp Stack.h Queue.cpp Queue.h NodeIterator.cpp NodeIterator.h ConstNodeIterator.h ConstNodeIterator.cpp ReverseIterator.cpp ReverseIterator.h)
