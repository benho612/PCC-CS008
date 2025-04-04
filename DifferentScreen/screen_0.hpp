//
// Created by hoben on 4/20/2023.
//
#include "cScreen.h"
#ifndef SFMLTU_SCREEN_0_HPP
#define SFMLTU_SCREEN_0_HPP
class screen_0 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    screen_0(void);
    virtual int Run(sf::RenderWindow &App);
};
#endif //SFMLTU_SCREEN_0_HPP
