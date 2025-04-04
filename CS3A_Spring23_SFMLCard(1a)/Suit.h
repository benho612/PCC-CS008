//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_SUIT_H
#define CS3A_SPRING23_SFMLCARD_SUIT_H
#include <SFML/Graphics.hpp>
#include "Suits.h"
#include "Images.h"
class Suit : public sf::Sprite
{
private:
    sf::Sprite sprite;
public:
    Suit();
    Suit(Suits suit);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Sprite& getSprite();
};


#endif //CS3A_SPRING23_SFMLCARD_SUIT_H
