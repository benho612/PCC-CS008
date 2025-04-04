//
// Created by hoben on 9/6/2023.
//
//player One is X, player Two is O
#ifndef TICTAGTOE_TICTACTOE_H
#define TICTAGTOE_TICTACTOE_H

#include <string>
#include <iostream>
#include <iomanip>
class ticTacToe {
public:
    ticTacToe();
    void displayBoard();
    void set(int choice);
    bool winCondition();
    void out();
    void result();
private:
    char turn = 'X';
    int rows, cols;
    bool playerOne = true, playerTwo = false;
    char board [3][3] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'}};

};


#endif //TICTAGTOE_TICTACTOE_H
