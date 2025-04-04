//
// Created by hoben on 3/29/2023.
//

#ifndef SFMLTU_COMPONENT_H
#define SFMLTU_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "States.h"
class Component: virtual public sf::Drawable, public States {
public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;

};


#endif //SFMLTU_COMPONENT_H
