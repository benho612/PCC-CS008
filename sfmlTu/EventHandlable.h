//
// Created by hoben on 4/6/2023.
//

#ifndef SFMLTU_EVENTHANDLABLE_H
#define SFMLTU_EVENTHANDLABLE_H
#include "SFML/Graphics.hpp"
class EventHandlable
{
public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
};

#endif //SFMLTU_EVENTHANDLABLE_H
