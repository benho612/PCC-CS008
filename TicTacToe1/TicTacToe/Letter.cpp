//
// Created by Dave R. Smith on 9/12/23.
//

#include "Letter.h"

Letter::Letter()
{

}
Letter::Letter(char letter) : letter(letter)
{
}
char Letter::getLetter() const
{
    return letter;
}

void Letter::setLetter(char letter)
{
    this->letter = letter;
}

std::ostream &operator<<(std::ostream &os, const Letter &letter)
{
    os <<  letter.letter;
    return os;
}

std::istream & operator >> (std::istream & in, Letter &player)
{
    in >> player.letter;
    return in;
}
