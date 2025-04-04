//
// Created by Dave R. Smith on 2/14/23.
//

#ifndef CS3A_SPRING23_SFMLCARD_BACKGROUND_H
#define CS3A_SPRING23_SFMLCARD_BACKGROUND_H
#include <SFML/Graphics.hpp>
class Background
{
private:
    sf::RectangleShape rectangle;
public:
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    Background();
    sf::RectangleShape& getRectangle();
    sf::FloatRect getPosition();
    void setPosition(float x, float y);
};


#endif //CS3A_SPRING23_SFMLCARD_BACKGROUND_H
