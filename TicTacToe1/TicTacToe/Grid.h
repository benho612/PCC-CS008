//
// Created by Dave R. Smith on 9/12/23.
//

#ifndef CS8FALL23_TICTACTOE_GRID_H
#define CS8FALL23_TICTACTOE_GRID_H

#include "Letter.h"
#include <vector>
#include <iostream>
class Grid
{
private:
    std::vector<std::vector<Letter>> grid;

public:
    Grid();
    std::vector<Letter>& operator[](unsigned int index);
    const std::vector<Letter>& operator[](unsigned int index) const;
    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);
    void set(int space, const Letter& letter);
    void reset();
};


#endif //CS8FALL23_TICTACTOE_GRID_H
