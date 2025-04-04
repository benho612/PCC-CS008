//
// Created by Dave R. Smith on 9/12/23.
//

#ifndef CS8FALL23_TICTACTOE_GAMELOGIC_H
#define CS8FALL23_TICTACTOE_GAMELOGIC_H


#include "Grid.h"

class GameLogic
{
public:
    bool isFilled(const Grid& grid);
    bool isHorizontal(const Grid& grid, const Letter& letter);
    bool isVertical(const Grid& grid, const Letter& letter);
    bool isDiagonal(const Grid& grid, const Letter& letter);
    bool isValid(const Grid& grid, int space);


};


#endif //CS8FALL23_TICTACTOE_GAMELOGIC_H
