//
// Created by hoben on 9/18/2023.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H


#include <string>
#include <iostream>
class board {
public:
    board();
    void createBoard();
    void updateBoard(int misses);
    void printBoard();
private:
    std::string HangManBoard;
};


#endif //TICTACTOE_BOARD_H
