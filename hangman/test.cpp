//
// Created by hoben on 1/17/2023.
//

#include "test.h"
#include <iostream>
#include <string>
void testBoard()
{
    std::string board;
    board = getDefaultBoard();
    for (int i = 0; i < 7; ++i) {
        updateDrawBoard(board,i);
        std::cout<<board<< std::endl;
    }
}
