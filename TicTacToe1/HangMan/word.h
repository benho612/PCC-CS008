//
// Created by hoben on 9/19/2023.
//

#ifndef TICTACTOE_WORD_H
#define TICTACTOE_WORD_H


#include "letterBank.h"

class word: public letterBank {
public:
    word();
    bool CheckInWord(char& letter);
    void phraseToDashes();
    void updateWord(char& letter);
    void printPhrase();
    void setPhrase();
    void printPhrase_dashes();
    bool isSame();
private:
    std::string phrase;
    std::string phrase_dashes;

};


#endif //TICTACTOE_WORD_H
