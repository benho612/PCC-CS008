//
// Created by hoben on 10/17/2023.
//

#ifndef N_QUEENS_RECURSIVE__N_QUEEN_H
#define N_QUEENS_RECURSIVE__N_QUEEN_H

#include <vector>

class N_Queen {
public:
    bool Place(int row, int column);
    void solveNQueens(int k);
    N_Queen();
    N_Queen(int n);
    void printBoard();
private:
    int n;
    std::vector<int> board;
};


#endif //N_QUEENS_RECURSIVE__N_QUEEN_H
