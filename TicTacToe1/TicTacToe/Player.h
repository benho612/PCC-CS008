//
// Created by Dave R. Smith on 9/12/23.
//

#ifndef CS8FALL23_TICTACTOE_PLAYER_H
#define CS8FALL23_TICTACTOE_PLAYER_H


#include "Letter.h"
#include <iostream>
class Player : public Letter
{

public:
    Player(const Letter& mark);
    Player();
    int choose();


};


#endif //CS8FALL23_TICTACTOE_PLAYER_H
