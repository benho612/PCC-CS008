//
// Created by hoben on 3/21/2023.
//

#ifndef POKERANALYSIS_DECK_H
#define POKERANALYSIS_DECK_H

#include "Card.h"

class Deck {
private:
    void load();
    Card deck[52];// this is your final deck of cards
public:
    Deck(); // this is the constructor
    const int DECK_SIZE = 52;// this is the size of your deck
    bool empty() const; //returns true if deck has no cards
    int cardIndex; //marks the index of the next card in the deck
    void shuffle(); // puts cards in random order
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index);// gets the Card at the given index
    void swap(Card& a,Card&b);
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console

};


#endif //POKERANALYSIS_DECK_H
