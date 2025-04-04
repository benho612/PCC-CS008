//
// Created by Dave R. Smith on 2/14/23.
//

#include "Card.h"

Card::Card(){
}

Card::Card(Ranks rank, Suits suit):suit(suit), rank(rank),width(100),height(100){
    setRectPosition();
    update();
    setColor(suit);
}

void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    background.draw(window,sf::RenderStates());
    rank.draw(window,sf::RenderStates());
    suit.draw(window,sf::RenderStates());

}

void Card::setRectPosition() {
    this->background.setPosition(width,height);
}

void Card::update() {
    Position::center(this->background.getRectangle(),this->suit.getSprite());
    Position::topLeft(this->background.getRectangle(),this->rank.getTop());
    Position::bottomRight(this->background.getRectangle(),this->rank.getBottom());

}


void Card::setColor(Suits color) {
    if (Rank::getColor(color) == "HEARTS" || Rank::getColor(color) == "DIAMONDS")
    {
        this->rank.getTop().setFillColor(sf::Color::Red);
        this->rank.getBottom().setFillColor(sf::Color::Red);
    }
    else
    {
        this->rank.getTop().setFillColor(sf::Color::Black);
        this->rank.getBottom().setFillColor(sf::Color::Black);
    }
}



