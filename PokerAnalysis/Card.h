//
// Created by hoben on 3/21/2023.
//

#ifndef POKERANALYSIS_CARD_H
#define POKERANALYSIS_CARD_H

#include <iostream>
#include "suits.h"
#include "ranks.h"

class Card {
public:
    suits suit;
    ranks value;
    std::string getSuit()const;
    std::string getRank()const;
    void setSuit(suits suit);
    void setRank(ranks value);
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    Card(suits suit, ranks string);
    Card();
    int getRankValue() const;
    int getSuitValue() const;
};


#endif //POKERANALYSIS_CARD_H
