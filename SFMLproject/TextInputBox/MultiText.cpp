//
// Created by Ben Ho on 10/22/2023.
//

#include "MultiText.h"

MultiText::MultiText():font(Font::getFont(Font::arial)),characterSize(30){
}

MultiText::MultiText(unsigned int characterSize):font(Font::getFont(Font::arial)),characterSize(characterSize) {
}


void MultiText::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(isActiving)
    {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
                if (event.text.unicode == '\b' && !this->letters.empty()) {
                    enableStates(BACKSPACE);
                }
                else if(event.text.unicode == 13 && !this->inputText.empty()){
                    enableStates(ENTER);
                }
                else if (event.text.unicode != '\b' && !KeyboardShortcut::isUndo()) {
                    enableStates(TYPINGMULTITEXT);
                    this->inputText = static_cast<char>(event.text.unicode);
                }
            }
        }
    }

}

void MultiText::update() {

    if(checkStates(ENTER))
    {
        this->letters.clear();
        this->inputText.clear();
        disableStates(ENTER);
    }

    if(checkStates(TYPINGMULTITEXT))
    {
        this->addCharacter();
        disableStates(TYPINGMULTITEXT);
    }

    if(checkStates(BACKSPACE))
    {
        this->inputText.clear(); // Handle backspace
        this->letters.pop_back();
        this->_curPosition = this->letters.back().getPosition();
        disableStates(BACKSPACE);
    }

}

void MultiText::addCharacter() {
    Letter c(this->inputText,this->font,this->characterSize);
    if(isdigit(c.getLetter()))
    {
        c.setFillColor(sf::Color::Red);
    }
    else if(isOperator(c.getLetter()))
    {
        c.setFillColor(sf::Color::Green);
    }
    else
    {
        c.setFillColor(sf::Color::Black);
    }
    this->push_back(c);
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(auto& i: letters)
    {
        window.draw(i);
    }
}

MultiText::iterator MultiText::begin() {
    return letters.begin();
}

MultiText::iterator MultiText::end() {
    return letters.end();
}

MultiText::const_iterator MultiText::cbegin() const {
    return letters.cbegin();
}

MultiText::const_iterator MultiText::cend() const {
    return letters.cend();
}

float MultiText::getAdvance(const Letter &letter) {
    const sf::Glyph& glyph = letter.getFont()->getGlyph(letter.getLetter(),
                                                        letter.getCharacterSize(), false
                                                        ,letter.getOutlineThickness());
    return glyph.advance;
}

void MultiText::push_back(const Letter &letter) {
    sf::Vector2f temp = _curPosition;
    if(!this->letters.empty())
    {
        temp = this->letters.back().getPosition() + sf::Vector2f(this->getAdvance(this->letters.back()),0);
    }
    this->letters.push_back(letter);
    this->letters.back().setPosition(temp);
    this->_curPosition = temp;
}

Snapshot MultiText::getSnapshot() const {
    return Snapshot(inputText);//this->getString()
}

void MultiText::applySnapshot(const Snapshot &snapshot) {
    this->inputText.clear();
    this->letters.clear();
    for(auto i : snapshot.getState())
    {
        Letter c(i,this->font,this->characterSize);
        push_back(c);
    }
}

void MultiText::setHistoryNode() {
    HistoryNode node(getSnapshot(), *this);
    History::pushHistory(node);
}

std::string MultiText::getString() const {
    std::string tempString;
    for(auto& i: this->letters)
        tempString += i.getLetter();

    return tempString;
}

bool MultiText::isOperator(char ch) {
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return true;
    else
        return false;
}


sf::Vector2f MultiText::getPosition() const {
    if(this->letters.empty())
        return this->_curPosition;
    else
        return this->letters.back().getPosition();
}

void MultiText::setPosition(const sf::Vector2f &position) {
    this->_curPosition = (position);
}

void MultiText::setString(const std::string &word) {
    this->letters.clear();
    this->inputText.clear();

    for (char i : word) {
        seperateAddCharacter(i);
    }
}

void MultiText::seperateAddCharacter(char letter) {
    Letter c(letter,this->font,this->characterSize);
    if(isdigit(c.getLetter()))
    {
        c.setFillColor(sf::Color::Red);
    }
    else if(isOperator(c.getLetter()))
    {
        c.setFillColor(sf::Color::Green);
    }
    else
    {
        c.setFillColor(sf::Color::Black);
    }
    this->push_back(c);
}


sf::FloatRect MultiText::getGlobalBounds() const {
    if(!this->letters.empty())
        return this->letters.back().getGlobalBounds();
}

sf::FloatRect MultiText::getLocalBounds() const {
    return this->letters.back().getLocalBounds();
}

const std::list<Letter> &MultiText::getLetters() const {
    return this->letters;
}

std::list<Letter> &MultiText::getLetters() {
    return this->letters;
}

unsigned int MultiText::getCharacterSize() const {
    return this->characterSize;
}

sf::Vector2f MultiText::getCurPosition() const {
    return this->_curPosition;
}

bool MultiText::isEmpty() {
    return this->letters.empty();
}

void MultiText::setActive(bool active) {
    this->isActiving = active;
}

bool MultiText::isActive(ScreenType screen) const {
    return false;
}

void MultiText::setCharacterSize(int size) {
    characterSize = size;
}





