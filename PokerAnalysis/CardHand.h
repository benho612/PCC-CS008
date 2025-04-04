//
// Created by hoben on 3/21/2023.
//

#ifndef POKERANALYSIS_CARDHAND_H
#define POKERANALYSIS_CARDHAND_H

#include "Deck.h"

class CardHand {
private:
    std::vector<Card> cardHand;
public:
    CardHand();
    void addCard(Card card);
    friend std::ostream& operator<<(std::ostream& out, const CardHand& cardHand);
    int getSize() const ;
    Card& getHandCardAt(int index);
    int getHandCardValueAt(int index);
};


#endif //POKERANALYSIS_CARDHAND_H
