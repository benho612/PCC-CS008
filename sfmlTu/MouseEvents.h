//
// Created by hoben on 3/30/2023.
//

#ifndef SFMLTU_MOUSEEVENTS_H
#define SFMLTU_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"

class MouseEvents {
public:

    static bool isHovered(const sf::FloatRect& bounds, const sf::RenderWindow& window);
    static bool isClicked(const sf::FloatRect& bounds, const sf::RenderWindow& window);
};


#endif //SFMLTU_MOUSEEVENTS_H
