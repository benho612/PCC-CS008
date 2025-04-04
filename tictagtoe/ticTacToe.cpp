//
// Created by hoben on 9/6/2023.
//

#include "ticTacToe.h"

ticTacToe::ticTacToe()
{
  rows = 0;
  cols = 0;
}


void ticTacToe::displayBoard() {
    for (auto & i : board) {
        for (char j : i) {
            std::cout << j <<" ";
        }
        std::cout << std::endl;
    }
}

void ticTacToe::set(int choice) {
    switch (choice)
    {
        case 1: rows = 0; cols = 0; break;
        case 2: rows = 0; cols = 1; break;
        case 3: rows = 0; cols = 2; break;
        case 4: rows = 1; cols = 0; break;
        case 5: rows = 1; cols = 1; break;
        case 6: rows = 1; cols = 2; break;
        case 7: rows = 2; cols = 0; break;
        case 8: rows = 2; cols = 1; break;
        case 9: rows = 2; cols = 2; break;
        default:
            std::cout <<"Invalid choice \n"; break;
    }
    if(turn == 'X' && board[rows][cols] != 'X' && board[rows][cols] != 'O'){
        //updating the position for 'X'
        board[rows][cols] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[rows][cols] != 'X' && board[rows][cols] != 'O'){
        //updating the position for 'O'
        board[rows][cols] = 'O';
        turn = 'X';
    }else if(board[rows][cols] == 'X' || board[rows][cols] == 'O'){
        std::cout<<"Already Claim";
        exit(0);
    }
}



bool ticTacToe::winCondition() {
    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;
}

void ticTacToe::out() {
    if(playerOne && !playerTwo)
    {
        std::cout <<"Enter your choice (1~9) PlayerOne 'X': ";
        playerOne = false;
        playerTwo = true;
    }
    else if(!playerOne && playerTwo)
    {
        std::cout <<"Enter your choice (1~9) PlayerTwo 'O': ";
        playerOne = true;
        playerTwo = false;
    }
}

void ticTacToe::result() {
    if(!playerOne)
        std::cout<<"PlayerOne win";
    else
        std::cout<<"PlayerTwo win";

}


