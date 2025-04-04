//
// Created by Dave R. Smith on 9/12/23.
//

#include "Game.h"

void Game::start()
{
    Player* p = &player1;
    int space;
    //ask player for their marks
    getPlayerMarks();
    do
    {
        //print the board
        std::cout << grid;
        //ask player to select a space
        do
        {
            std::cout << "Choose a space: ";
            space = p->choose();
            //if the sapce valid
        }
        while(!gameLogic.isValid(grid, space) || gameLogic.isFilled(grid));

        grid.set(space, p->getLetter());
        //check if they are a winner
        if(isWinner(*p))
        {
            displayWinner(*p);
            //exit(1);
            break;
        }
        p = p == &player1 ? &player2 : &player1;
    }
   while(!end());
   this->grid.reset();
}

bool Game::isWinner(Player player)
{
    return
        gameLogic.isDiagonal(grid, player) ||
        gameLogic.isHorizontal(grid, player) ||
        gameLogic.isVertical(grid, player) ;

}

void Game::displayWinner(Player player)
{
    std::cout << "Player " << player.getLetter() << " is the winner!";
}

void Game::getPlayerMarks()
{
    std::cout << "Player 1 choose your mark: ";
    std::cin >> player1;
    std::cout << "Player 2 choose your mark: ";
    std::cin >> player2;
}

bool Game::end()
{
    return !(isWinner(player1) || isWinner(player2)) && gameLogic.isFilled(grid);
}

/*int Game::Run(){
    start();
    this->grid.reset();
    return 0;
}*/

std::string Game::getTitle() {
    return "TicTacToe";
}
