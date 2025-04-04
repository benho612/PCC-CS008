//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_RANK_H
#define CS3A_SPRING23_SFMLCARD_RANK_H

#include <SFML/Graphics.hpp>
#include "Ranks.h"
#include "Background.h"
#include "Font.h"
#include "Suit.h"
class Rank : public sf::Drawable
{
private:
    sf::Text top, bottom;
public:
    Rank();
    Rank(Ranks rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setSize(float size);
    void setFont();
    sf::Text &getTop();
    sf::Text &getBottom();
    static std::string getColor(Suits suit);
    };


#endif //CS3A_SPRING23_SFMLCARD_RANK_H
