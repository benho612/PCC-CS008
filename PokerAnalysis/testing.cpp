//
// Created by hoben on 3/21/2023.
//
#include "Deck.h"
#include <ctime>
#include "PokerScore.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include "Application.h"
#include "rowOfCard.h"
#include "SfmlScore.h"
int main() {
    srand(time(nullptr));
    PokerScore total;
    int timeOfRunningProgram = 700000;

    for (int i = 0; i < timeOfRunningProgram; ++i) {
         Deck deck;
         CardHand ch;
         for (int j = 0; j < 5; j++)
         {
             ch.addCard(deck.dealCard());
         }
         total+= CardHandScorer::scorePokerHand(ch);
     }
     total.PokerAnaylsis(total);
     std::cout<<total;

     rowOfCard test;
     SfmlScore scoreboard(total, timeOfRunningProgram);
     Application::addComponents(test);
     Application::addComponents(scoreboard);
     Application::run();
    return 0;



}