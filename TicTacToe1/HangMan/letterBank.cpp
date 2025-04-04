//
// Created by hoben on 9/18/2023.
//

#include <iostream>
#include "letterBank.h"

void letterBank::outputWordBank() {
    for (auto & i: wordBank) {
        std::cout << i << " ";
    }
}

void letterBank::inputWordBankFromFile() {
    std::ifstream fin;
    std::string string;
    int i = 0;
    FileIO::openFile(fin, "HangMan/idioms.txt");
    while(!(fin.eof()))
    {
        std::getline(fin,string);
        wordBank.push_back(string);
        i++;
    }
    fin.close();
}

letterBank::letterBank() {
    inputWordBankFromFile();
}

const std::vector<std::string> &letterBank::getWordBank() const {
    return wordBank;
}
