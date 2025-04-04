#include <iostream>
#include "BST.h"

void output(int &data)
{
    std::cout << data << " ";
}

int main() {
    BST<int> tree;
    tree.push(10);
    tree.push(2);
    tree.push(16);
    tree.push(1);
    tree.push(20);
    tree.push(22);
    //tree.PostOrder(output);
    tree.remove(10);
    tree.PreOrder(output);
    return 0;
}