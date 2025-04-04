//
// Created by hoben on 9/18/2023.
//

#ifndef TICTACTOE_LETTERBANK_H
#define TICTACTOE_LETTERBANK_H

#include <fstream>
#include <vector>
#include <string>
#include "../FileIO.h"
class letterBank {
public:
    void outputWordBank();
    void inputWordBankFromFile();
    letterBank();
    const std::vector<std::string> &getWordBank() const;

private:
    std::vector<std::string> wordBank;
};


#endif //TICTACTOE_LETTERBANK_H
