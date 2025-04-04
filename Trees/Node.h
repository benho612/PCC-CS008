//
// Created by hoben on 10/24/2023.
//

#ifndef TREES_NODE_H
#define TREES_NODE_H

template <typename T>
class Node {
public:
    char value;
    T data;
    Node<T>* leftChild, *rightChild;
private:
};

#endif //TREES_NODE_H
