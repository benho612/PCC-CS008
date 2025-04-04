//
// Created by Ben Ho on 9/17/2023.
//

#ifndef TICTACTOE_HANGMAN_H
#define TICTACTOE_HANGMAN_H


#include "../gameInterface/Component.h"
#include "board.h"
#include "letterBank.h"
#include "word.h"
class hangMan: public Component {
private:
    board board;
    letterBank letterBank;
    word word;
    int misses = 0;
public:
    void start();
    bool end();
    std::string getTitle();
    hangMan();
    void final();
};


#endif //TICTACTOE_HANGMAN_H
