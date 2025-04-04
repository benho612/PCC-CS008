//
// Created by hoben on 9/19/2023.
//

#include <iostream>
#include "word.h"

bool word::CheckInWord(char& letter) {
    return phrase.find(letter) != std::string::npos;
}


void word::updateWord(char& letter) {
    if(CheckInWord(letter)){
        for (int i = 0; i < phrase.size(); ++i) {
            if(phrase[i] == letter)
                phrase_dashes[i] = letter;
        }
    }
}

void word::setPhrase() {
    phrase = getWordBank().at(rand() % getWordBank().size());
}

void word::printPhrase() {
    std::cout << phrase << std::endl;
}

void word::phraseToDashes() {
    for (auto& i : phrase) {
        if(i == ' ')
            phrase_dashes += ' ';
        else
            phrase_dashes += '_';
    }
}

void word::printPhrase_dashes() {
    std::cout << phrase_dashes << std::endl;
}

word::word() {
    setPhrase();
    phraseToDashes();
}


bool word::isSame() {
    return (phrase == phrase_dashes);
}

