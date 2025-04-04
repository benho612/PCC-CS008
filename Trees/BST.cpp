//
// Created by hoben on 10/24/2023.
//
#ifndef TREES_BST_CPP
#define TREES_BST_CPP

#include "BST.h"

template<typename T>
BST<T>::BST(){
    _root = nullptr;
}

template<typename T>
void BST<T>::clear() {
    this->~BST();

}

template<typename T>
BST<T>::~BST() {
    deleteRecursive(_root);
    _root = nullptr;
}

template<typename T>
void BST<T>::deleteRecursive(Node<T> *root) {
    if(!root)
        return ;
    deleteRecursive(root->leftChild);
    deleteRecursive(root->rightChild);
    delete root;
}

template<typename T>
BST<T>::BST(const BST<T> &oldBST):BST() {
    *this = oldBST;
}

template<typename T>
void BST<T>::copy(Node<T>* root) {
    if(root == nullptr)
        return ;

    push(root->data);
    copy(root->leftChild);
    copy(root->rightChild);

}

template<typename T>
BST<T> &BST<T>::operator=(const BST<T> &oldObj) {
   if(this != &oldObj)
   {
       clear();
       copy(oldObj._root);
   }
   return * this;
}

template<typename T>
void BST<T>::breadthFirst(void(*f)(T&data)) {
    std::queue<Node<T>*> queue;
    queue.push(_root);
    while(!queue.empty())
    {
        if(!queue.front())
        {
            queue.pop();
            continue;
        }
        f(queue.front()->data);
        queue.push(queue.front()->leftChild);
        queue.push(queue.front()->rightChild);
        queue.pop();
    }
}

template<typename T>
void BST<T>::PreOrder(void (*f)(T &)) {
    PreOrderRecursive(f,_root);
}

template<typename T>
void BST<T>::PreOrderRecursive(void (*f)(T &), Node<T> *root) {
    if(root == nullptr)
    {
        return;
    }
    f(root->data);
    PreOrderRecursive(f,root->leftChild);
    PreOrderRecursive(f,root->rightChild);
}

template<typename T>
void BST<T>::InOrder(void (*f)(T &)) {
    InOrderRecursive(f,_root);
}

template<typename T>
void BST<T>::InOrderRecursive(void (*f)(T &), Node<T> *root) {
    if(root == nullptr)
        return;
    InOrderRecursive(f,root->leftChild);
    f(root->data);
    InOrderRecursive(f,root->rightChild);
}

template<typename T>
void BST<T>::PostOrder(void (*f)(T &)) {
    PostOrderRecursive(f, _root);
}

template<typename T>
void BST<T>::PostOrderRecursive(void (*f)(T &), Node<T> *root) {
    if (root == nullptr)
        return ;

    PostOrderRecursive(f,root->leftChild);
    PostOrderRecursive(f,root->rightChild);
    f(root->data);
}

template<typename T>
Node<T> *BST<T>::CreateNode(T data) {
    auto* newNode = new Node<T>();
    newNode->data = data;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    return newNode;
}

template<typename T>
void BST<T>::push(T data) {
    if(!_root)
        _root = CreateNode(data);
    else
        recursivePush(CreateNode(data), _root);
}

template<typename T>
void BST<T>::recursivePush(Node<T> *PushNode, Node<T> *root) {
    if(!root)
        return;

    if(PushNode->data <= root->data)
    {
        if(!root->leftChild)
            root->leftChild = PushNode;
        else
            recursivePush(PushNode,root->leftChild);
    }
    else if(PushNode->data > root->data)
    {
        if(!root->rightChild)
            root->rightChild = PushNode;
        else
            recursivePush(PushNode,root->rightChild);
    }
}

template<typename T>
Node<T>* BST<T>::recursiveRemove(Node<T>* root, const T& data) {
    if (root == nullptr)
    {
        return root;
    }

    if (data < root->data)
    {
        root->leftChild = recursiveRemove(root->leftChild, data);
    }
    else if (data > root->data)
    {
        root->rightChild = recursiveRemove(root->rightChild, data);
    }
    else
    {
        if (root->leftChild == nullptr) {
            Node<T> *temp = root->rightChild;
            delete root;
            return temp;
        } else if (root->rightChild == nullptr) {
            Node<T> *temp = root->leftChild;
            delete root;
            return temp;
        }
        Node<T> *temp = minValueNode(root->rightChild);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->rightChild = recursiveRemove(root->rightChild, temp->data);
    }
    return root;
}

template<typename T>
Node<T>* BST<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;
    while (current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}

template<typename T>
void BST<T>::remove(const T &data) {
    recursiveRemove(_root,data);
}

template<typename T>
Node<T>* BST<T>::search(const T& data) {
    if(data != nullptr)
        return nullptr;

    if(data == _root->data)
        return _root;

    if(data <= _root->data)
        search(_root->leftChild);
    else if(data > _root->data)
        search(_root->rightChild);

}


#endif //TREES_BST_CPP
