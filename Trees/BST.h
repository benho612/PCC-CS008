//
// Created by hoben on 10/24/2023.
//

#ifndef TREES_BST_H
#define TREES_BST_H
#include "Node.h"
#include <queue>
template <typename T>
class BST {
public:
    void InOrder(void (*f)(T& data));
    void PreOrder(void (*f)(T& data));
    void PostOrder(void(*f)(T&data));
    BST();
    ~BST();
    BST(const BST<T>& oldBST);
    void copy(Node<T>* root);
    void breadthFirst(void(*f)(T&data));
    void push(T data);
    Node<T>* CreateNode(T data);
    BST<T>&operator =(const BST<T>& oldObj);
    void clear();
    void remove(const T& data);

private:
    void PreOrderRecursive(void (*f)(T& data), Node<T>* root);
    void InOrderRecursive(void (*f)(T& data), Node<T>* root);
    void PostOrderRecursive(void (*f)(T& data), Node<T>* root);
    void recursivePush(Node<T>* PushNode, Node<T>* root);
    void deleteRecursive(Node<T>* root);
    Node<T>* _root;
    Node<T>* search(const T& data);
    Node<T>* recursiveRemove(Node<T>* root, const T& data);
    Node<T>* minValueNode(Node<T>* node);
};



#include "BST.cpp"

#endif //TREES_BST_H
