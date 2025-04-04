//
// Created by hoben on 4/20/2023.
//

#ifndef SFMLTU_CSCREEN_H
#define SFMLTU_CSCREEN_H
#include "SFML/Graphics.hpp"

class cScreen
{
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};


#endif //SFMLTU_CSCREEN_H
