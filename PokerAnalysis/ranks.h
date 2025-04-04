//
// Created by hoben on 3/21/2023.
//

#ifndef POKERANALYSIS_RANKS_H
#define POKERANALYSIS_RANKS_H


enum ranks {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    //
};



namespace {
    std::vector<ranks> ranking{
            ranks::ACE, ranks::TWO, ranks::THREE, ranks::FOUR, ranks::FIVE,
            ranks::SIX, ranks::SEVEN, ranks::EIGHT, ranks::NINE, ranks::TEN,
            ranks::JACK, ranks::QUEEN, ranks::KING
    };
}
#endif //POKERANALYSIS_RANKS_H
