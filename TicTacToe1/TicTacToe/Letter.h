//
// Created by Dave R. Smith on 9/12/23.
//

#ifndef CS8FALL23_TICTACTOE_LETTER_H
#define CS8FALL23_TICTACTOE_LETTER_H


#include <iostream>

class Letter
{
private:
    char letter;
public:
    Letter(char letter);
    Letter();
    char getLetter() const;

    void setLetter(char letter);

    friend std::ostream &operator<<(std::ostream &os, const Letter &letter);
    friend std::istream & operator >> (std::istream & in, Letter &player);
};


#endif //CS8FALL23_TICTACTOE_LETTER_H
