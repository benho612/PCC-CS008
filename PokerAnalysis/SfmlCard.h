//
// Created by Ben Ho on 4/3/2023.
//

#ifndef POKERANALYSIS_SFMLCARD_H
#define POKERANALYSIS_SFMLCARD_H
#include "Component.h"
#include "Suits.h"
#include "Ranks.h"
#include <vector>
class SfmlCard :public Component{
private:
    sf::Sprite card;
    sf::IntRect intRect;
    static sf::Texture texture;
    void updateCard(ranks rank, suits suit);
public:
    void setPosition(sf::Vector2f position);
    void setScale(sf::Vector2f position);
    SfmlCard();
    SfmlCard(ranks rank, suits suit);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    int getWidth();
    int getHeight();
    int getLeft();
};


#endif //POKERANALYSIS_SFMLCARD_H
