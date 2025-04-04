//
// Created by hoben on 10/17/2023.
//

#include <iostream>
#include "N_Queen.h"



bool N_Queen::Place(int row, int column) {
    for (int j = 0; j < row; ++j) {
        if((board[j] == column || std::abs(board[j] - column) == std::abs(j - row)) )
            return false;
    }
        return true;
}

void N_Queen::solveNQueens(int k) {
    for (int i = 0; i < n; ++i) {
        if (Place(k,i))
        {
            board[k] = i;
            if(k == n-1)
                printBoard();
            else
                solveNQueens(k+1);
        }
    }
}
void N_Queen::printBoard() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j)
                std::cout << "Q";
            else
                std::cout << ".";
        }
        std::cout <<"\n";
    }
    std::cout << "\n";
}

N_Queen::N_Queen():n(0),board(0, 0) {

}

N_Queen::N_Queen(int n):n(n),board(n, 0) {

}



