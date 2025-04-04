//
// Created by Ben Ho on 10/22/2023.
//

#include <iostream>
#include "MultiText.h"

MultiText::MultiText():font(Font::getFont("arial.ttf")),characterSize(30){
}

MultiText::MultiText(unsigned int characterSize):font(Font::getFont("arial.ttf")),characterSize(characterSize) {
}


void MultiText::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            if (event.text.unicode == '\b' && !letters.empty()) {
                inputText.clear(); // Handle backspace
                letters.pop_back();
                _curPosition = letters.back().getPosition();
            }
            else if(event.text.unicode == 13 && !inputText.empty()){
                setHistoryNode();
                letters.clear();
                inputText.clear();
            }
            else if (event.text.unicode != '\b' && !KeyboardShortcut::isUndo()) {
                inputText = static_cast<char>(event.text.unicode);
                addCharacter();
                setHistoryNode();
            }
        }
    }
}

void MultiText::update() {

}

void MultiText::addCharacter() {
    Letter c(inputText,font,characterSize);
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
    if(!letters.empty())
    {
        temp = letters.back().getPosition() + sf::Vector2f(this->getAdvance(letters.back()),0);
    }
    letters.push_back(letter);
    letters.back().setPosition(temp);
    _curPosition = temp;
}

Snapshot MultiText::getSnapshot() const {
    return Snapshot(this->getString());
}

void MultiText::applySnapshot(const Snapshot &snapshot) {
    inputText.clear();
    letters.clear();
    for(auto i : snapshot.getState())
    {
        Letter c(i,font,characterSize);
        push_back(c);
    }
}

void MultiText::setHistoryNode() {
    HistoryNode node(getSnapshot(), *this);
    History::pushHistory(node);
}

std::string MultiText::getString() const {
    std::string tempString;
    for(auto& i: letters)
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
    if(letters.empty())
        return _curPosition;
    else
        return letters.back().getPosition();
}

void MultiText::setPosition(const sf::Vector2f &position) {
    _curPosition = (position);
}

void MultiText::setString(const std::string &word) {
    letters.clear();
    inputText.clear();

    for (int i = 0; i < word.size(); ++i) {
        seperateAddCharacter(word[i]);
    }
}

void MultiText::seperateAddCharacter(char letter) {
    Letter c(letter,font,characterSize);
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
    if(!letters.empty())
        return letters.back().getGlobalBounds();
}

sf::FloatRect MultiText::getLocalBounds() const {
    return letters.back().getLocalBounds();
}

const std::list<Letter> &MultiText::getLetters() const {
    return letters;
}

std::list<Letter> &MultiText::getLetters() {
    return letters;
}

unsigned int MultiText::getCharacterSize() const {
    return characterSize;
}

sf::Vector2f MultiText::getCurPosition() const {
    return _curPosition;
}

bool MultiText::isEmpty() {
    return letters.empty();
}





