//
// Created by Dave R. Smith on 9/12/23.
//

#ifndef CS8FALL23_TICTACTOE_GAME_H
#define CS8FALL23_TICTACTOE_GAME_H


#include "Grid.h"
#include "GameLogic.h"
#include "Player.h"
#include "../gameInterface/Component.h"
#include <iostream>

class Game: public Component
{
private:
    Grid grid;
    GameLogic gameLogic;
    Player player1, player2;

public:
    void start();
    bool end();
    bool isWinner(Player player);
    void displayWinner(Player player);
    void getPlayerMarks();
    std::string getTitle();
    //int Run();
    //void leaderBoard();
};


#endif //CS8FALL23_TICTACTOE_GAME_H
