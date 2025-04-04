//
// Created by Dave R. Smith on 9/12/23.
//

#include "Grid.h"

Grid::Grid() : grid(3, std::vector<Letter>(3, Letter()))
{
    char num = '1';
    for (int i = 0; i < grid.size(); ++i)
    {

        for (int j = 0; j < grid[i].size(); ++j)
        {

            grid[i][j].setLetter(num++);
        }
    }
}

std::vector<Letter> &Grid::operator[](unsigned int index)
{
    return grid[index];
}

const std::vector<Letter> &Grid::operator[](unsigned int index) const
{
    return grid[index];
}
void Grid::set(int space, const Letter &letter)
{
    grid[(space - 1)/3][(space - 1) % 3] = letter;
}

std::ostream &operator<<(std::ostream &out, const Grid &grid)
{
    for (int i = 0; i < grid.grid.size(); ++i)
    {

        for (int j = 0; j < grid.grid[i].size(); ++j)
        {

           out << grid.grid[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

void Grid::reset() {
    char num = '1';
    for (int i = 0; i < grid.size(); ++i)
    {

        for (int j = 0; j < grid[i].size(); ++j)
        {

            grid[i][j].setLetter(num++);
        }
    }
}
