//
// Created by Ben Ho on 9/17/2023.
//

#include "hangMan.h"

hangMan::hangMan() {
}

std::string hangMan::getTitle()
{
    return "hangMan";
}

void hangMan::start() {
    do{
        char letter;
        board.printBoard();
        word.printPhrase_dashes();
        word.printPhrase();
        std::cout << "Enter a Letter\n";
        std::cin >> letter;
        if (word.CheckInWord(letter))
        {
            word.updateWord(letter);
            std::cout << "Correct\n";
        }
        else
        {
            std::cout <<"Wrong\n";
            misses++;
            board.updateBoard(misses);
        }
    }while(!end());
    final();
}


bool hangMan::end() {
    if(misses >= 6 || word.isSame())
        return true;
    else
        return false;
}

void hangMan::final() {
    board.printBoard();
    word.printPhrase();
    misses >=6 ? std::cout << "you lose" <<std::endl : std::cout <<"you win" <<std::endl;
}
