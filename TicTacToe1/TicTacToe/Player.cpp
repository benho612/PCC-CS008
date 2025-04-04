//
// Created by Dave R. Smith on 9/12/23.
//

#include "Player.h"

Player::Player() : Letter()
{

}

Player::Player(const Letter& mark) : Letter(mark.getLetter())
{

}

int Player::choose()
{
    int choice;
    std::cin >> choice;
    return choice;
}


