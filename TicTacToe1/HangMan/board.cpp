//
// Created by hoben on 9/18/2023.
//

#include "board.h"

void board::createBoard() {
    HangManBoard = "+---+\n"
            " |    |\n"
            "      |\n"
            "      |\n"
            "      |\n"
            "      |\n"
            "=========\n";
}

void board::updateBoard(int misses) {
    switch (misses){
        case 1: HangManBoard[15] = '0'; break;
        case 2: HangManBoard[23] = '|'; break;
        case 3: HangManBoard[22] = '/'; break;
        case 4: HangManBoard[24] = '\\'; break;
        case 5: HangManBoard[30] = '/'; break;
        case 6: HangManBoard[32] = '\\'; break;
        default: exit(1);

    }
}

void board::printBoard() {
    std::cout << HangManBoard;
}

board::board(){
    createBoard();
}
