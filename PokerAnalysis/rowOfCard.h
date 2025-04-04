//
// Created by Ben Ho on 4/3/2023.
//

#ifndef POKERANALYSIS_ROWOFCARD_H
#define POKERANALYSIS_ROWOFCARD_H
#include "SfmlCard.h"
#include "Application.h"

class rowOfCard:public Component {
private:
    int x = 0, y = 0;
    int counter = 0;
    std::vector<SfmlCard> rowsOfCard;
    void rowRoyalFlush();
    void rowStraightFlush();
    void rowFourOfAKind();
    void rowFullHouse();
    void rowFlush();
    void rowStraight();
    void rowThreeOfAKind();
    void rowTwoPair();
    void rowOnePair();
    void rowHighCard();
public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    rowOfCard();
    void addCard(SfmlCard& card);
};



#endif //POKERANALYSIS_ROWOFCARD_H
