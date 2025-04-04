//
// Created by hoben on 4/20/2023.
//

#ifndef SFMLTU_SCREEN_1_HPP
#define SFMLTU_SCREEN_1_HPP
#include "cScreen.h"
class screen_1 : public cScreen
{
private:
    float movement_step;
    float posx;
    float posy;
    sf::RectangleShape Rectangle;
public:
    screen_1(void);
    virtual int Run(sf::RenderWindow &App);
};
#endif //SFMLTU_SCREEN_1_HPP
