//
// Created by Ben Ho on 9/3/2023.
//

#include "interface.h"

interface::interface() {
    std::cout<<"how many rows are there gonna be?\n";
    std::cin >> rows;
    std::cout<<"how many cols are there gonna be?\n";
    std::cin >> cols;
}

int interface::getRows() const {
    return rows;
}

int interface::getCols() const {
    return cols;
}

