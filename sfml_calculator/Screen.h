//
// Created by hoben on 10/12/2023.
//

#ifndef SFML_CALCULATOR_SCREEN_H
#define SFML_CALCULATOR_SCREEN_H
#include <SFML/Graphics.hpp>
#include "Helper.h"
#include "Typing.h"
#include "Buttons.h"
class Screen: public SFMLObject {
private:
    Typing typing;
    sf::RectangleShape box;
    Buttons button;
public:
    Screen();
    Screen(const sf::Vector2f & dimensions, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
     sf::Vector2f getPosition() const;
     void setPosition(const sf::Vector2f & position);
     sf::FloatRect getGlobalBounds() const;
     sf::FloatRect getLocalBounds() const;
     void eventHAndler(sf::RenderWindow& renderWindow, sf::Event event) ;
     void update(float dt);
};


#endif //SFML_CALCULATOR_SCREEN_H
