//
// Created by hoben on 3/21/2023.
//

#include "Card.h"

const std::vector<std::string> RankValue = {"Ace","Two","Three","Four","Five","Six","Seven"
                                           ,"Eight","Nine","Ten","Jack","Queen","King"};

Card::Card() {
    value = ACE;
    suit = HEARTS;
}

Card::Card(suits suit, ranks string):suit(suit),value(string) {
}

std::string Card::getSuit() const {
    switch(suit)
    {
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        case CLUBS:
            return "Clubs";
        default:
            exit(1);
    }
}

std::string Card::getRank() const{

    return RankValue[value];
}

void Card::setSuit(suits suit) {
    this->suit = suit;
}

void Card::setRank(ranks value) {
    this->value = value;
}

int Card::getRankValue() const {
    switch(value){
        case ranks::ACE:
            return 1;
        case ranks::TWO:
            return 2;
        case ranks::THREE:
            return 3;
        case ranks::FOUR:
            return 4;
        case ranks::FIVE:
            return 5;
        case ranks::SIX:
            return 6;
        case ranks::SEVEN:
            return 7;
        case ranks::EIGHT:
            return 8;
        case ranks::NINE:
            return 9;
        case ranks::TEN:
            return 10;
        case ranks::JACK:
            return 11;
        case ranks::QUEEN:
            return 12;
        case ranks::KING:
            return 13;
    }
}

int Card::getSuitValue() const{
    switch(suit)
    {
        case DIAMONDS:
            return 1;
        case HEARTS:
            return 2;
        case SPADES:
            return 3;
        case CLUBS:
            return 4;
        default:
            exit(1);
    }
}

std::ostream &operator<<(std::ostream &out, const Card &card) {
        std::cout <<card.getRank() << " of "<<card.getSuit();
    return out;
}





