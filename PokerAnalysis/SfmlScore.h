//
// Created by Ben Ho on 4/3/2023.
//

#ifndef POKERANALYSIS_SFMLSCORE_H
#define POKERANALYSIS_SFMLSCORE_H

#include "PokerScore.h"
#include "SfmlSingleScore.h"
#include "Component.h"
#include <sstream>

class SfmlScore: public Component {
private:
    std::vector<SfmlSingleScore> GroupsOfText;
    PokerScore localScore;
    double timeRunningProgram;
public:
    SfmlScore();
    SfmlScore(PokerScore&score, const int timeRunning);
    void addText(SfmlSingleScore& text, int x, int y);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void RoyalFlush();
    void StraightFlush();
    void FourOfAKind();
    void FullHouse();
    void Flush();
    void Straight();
    void ThreeOfAKind();
    void TwoPair();
    void OnePair();
    void HighCard();


};


#endif //POKERANALYSIS_SFMLSCORE_H
