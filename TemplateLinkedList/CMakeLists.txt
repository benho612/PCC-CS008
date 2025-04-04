cmake_minimum_required(VERSION 3.24)
project(TemplateLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedListProject main.cpp LinkedList.cpp LinkedList.h Node.h Stack.cpp Stack.h testCaseForStack.cpp Queue.cpp Queue.h testCaseForQueue.cpp Palindrome.cpp Palindrome.h)
