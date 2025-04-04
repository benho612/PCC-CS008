//
// Created by Dave R. Smith on 9/12/23.
//

#include "GameLogic.h"

bool GameLogic::isFilled(const Grid &grid)
{
    for (int i = 0; i < 3; ++i)
    {
        for(int j=0; j<3; j++)
            if(!isalpha(grid[i][j].getLetter()))
                return false;
    }
    return true;
}

bool GameLogic::isHorizontal(const Grid &grid, const Letter &letter)
{
    bool found = false;
    for (int i = 0; i < 3; ++i)
    {

        if( grid[i][0].getLetter() == letter.getLetter() &&
            grid[i][1].getLetter() == letter.getLetter() &&
            grid[i][2].getLetter() == letter.getLetter())
            found = true;

    }
    return found;
}

bool GameLogic::isVertical(const Grid &grid, const Letter &letter)
{
    bool found = false;
    for (int i = 0; i < 3; ++i)
    {

        if( grid[0][i].getLetter() == letter.getLetter() &&
            grid[1][i].getLetter() == letter.getLetter() &&
            grid[2][i].getLetter() == letter.getLetter())
            found = true;

    }
    return found;
}

bool GameLogic::isDiagonal(const Grid &grid, const Letter &letter)
{
    return  grid[1][1].getLetter() == letter.getLetter() &&
            (grid[0][0].getLetter() == letter.getLetter() &&
            grid[2][2].getLetter() == letter.getLetter()) ||
            (grid[0][2].getLetter() == letter.getLetter() &&
            grid[2][0].getLetter() == letter.getLetter());
}

bool GameLogic::isValid(const Grid &grid, int space)
{
    return isdigit(grid[(space -1)/3][(space-1)%3].getLetter());
}
