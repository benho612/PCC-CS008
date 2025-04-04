//
// Created by hoben on 3/21/2023.
//

#ifndef POKERANALYSIS_CARDHANDSCORER_H
#define POKERANALYSIS_CARDHANDSCORER_H

#include <ostream>
#include "PokerScore.h"

class CardHandScorer {

public:
    static void sort(CardHand& hand);
    static void swap(Card& card1, Card& card2);
    static PokerScore scorePokerHand(CardHand hand);
};


#endif //POKERANALYSIS_CARDHANDSCORER_H
