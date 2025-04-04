//
// Created by hoben on 11/16/2023.
//

#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H


template <typename T, int MAX = 2>
class BTree
{
public:

    int data_count = 0;
    int child_count = 0;
    T data[MAX+1];
    BTree<T>* subset[MAX + 2];

};


#endif //B_TREE_BTREE_H
