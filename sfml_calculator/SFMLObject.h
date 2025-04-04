//
// Created by hoben on 10/12/2023.
//

#ifndef SFML_CALCULATOR_SFMLOBJECT_H
#define SFML_CALCULATOR_SFMLOBJECT_H
#include <SFML/Graphics.hpp>

class SFMLObject:public sf::Drawable{
public:
    virtual sf::Vector2f getPosition() const = 0;
    virtual void setPosition(const sf::Vector2f & position) = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::FloatRect getLocalBounds() const =0;
    virtual void eventHAndler(sf::RenderWindow& renderWindow, sf::Event event) = 0;
    virtual void update(float dt) = 0;
private:

};


#endif //SFML_CALCULATOR_SFMLOBJECT_H
