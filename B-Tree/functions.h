//
// Created by Dave R. Smith on 11/7/23.
//

#ifndef CS8FALL23_BTREE_FUNCTIONS_H
#define CS8FALL23_BTREE_FUNCTIONS_H
#include "BTree.h"
#include <vector>
#include <iostream>
#include <iomanip>


void makeTree(BTree<int> &tree, std::vector<int> data,
              std::vector<std::vector<int>> childData, int size);

void print(BTree<int>& tree, int depth);


BTree<int> createTree();

#endif //CS8FALL23_BTREE_FUNCTIONS_H
