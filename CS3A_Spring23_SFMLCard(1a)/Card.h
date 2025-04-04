//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_CARD_H
#define CS3A_SPRING23_SFMLCARD_CARD_H

#include "Background.h"
#include "Rank.h"
#include "Position.h"
#include "Suit.h"
#include <SFML/Graphics.hpp>
class Card : public sf::Drawable
{
private:
    Background background;
    Rank rank;
    Suit suit;
    float width, height;
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Card();
    Card(Ranks rank, Suits suit);
    void setRectPosition();
    void update();
    void setColor(Suits color);
};


#endif //CS3A_SPRING23_SFMLCARD_CARD_H
