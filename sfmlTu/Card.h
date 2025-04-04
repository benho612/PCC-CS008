//
// Created by hoben on 3/29/2023.
//

#ifndef SFMLTU_CARD_H
#define SFMLTU_CARD_H
#include "Component.h"
#include "Suits.h"
#include "Ranks.h"
class Card :public Component{
private:
    sf::Sprite background;
    sf::IntRect intRect;
    static sf::Texture texture;
    void updateCard(Ranks rank, Suits suit);
public:
    void setPosition(sf::Vector2f position);
    void eventHandler(sf::RenderWindow &window, sf::Event event) ;
    Card();
    Card(Ranks rank, Suits suit);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const ;
    void update();
};


#endif //SFMLTU_CARD_H
