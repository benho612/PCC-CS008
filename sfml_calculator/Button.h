//
// Created by hoben on 10/16/2023.
//

#ifndef SFML_CALCULATOR_BUTTON_H
#define SFML_CALCULATOR_BUTTON_H
#include <SFML/Graphics.hpp>
#include "SFMLObject.h"


class Button :public SFMLObject {
public:
    Button();
    Button(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f & position);
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;
    void eventHAndler(sf::RenderWindow& renderWindow, sf::Event event) ;
    void update(float dt);

private:
    sf::CircleShape button;
};


#endif //SFML_CALCULATOR_BUTTON_H
