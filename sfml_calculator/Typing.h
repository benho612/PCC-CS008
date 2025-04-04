//
// Created by hoben on 10/11/2023.
//

#ifndef SFML_CALCULATOR_TYPING_H
#define SFML_CALCULATOR_TYPING_H
#include <SFML/Graphics.hpp>
#include "SFMLObject.h"
#include "Helper.h"
#include "Font.h"
#include "RPN.h"
class Typing:public SFMLObject  {
private:
    sf::Text text;
    std::string inputText;
    double result = 0;
public:
    Typing();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Vector2f getPosition() const;
     void setPosition(const sf::Vector2f & position);
     sf::FloatRect getGlobalBounds() const;
     sf::FloatRect getLocalBounds() const;
     void eventHAndler(sf::RenderWindow& renderWindow, sf::Event event);
     void update(float dt) ;
};


#endif //SFML_CALCULATOR_TYPING_H
