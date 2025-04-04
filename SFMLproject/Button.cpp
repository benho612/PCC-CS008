//
// Created by hoben on 12/6/2023.
//

#include "Button.h"
#include "Helper/Positioning.h"

Button::Button() = default;

Button::Button(const std::string &_text) {
    setText(_text);
    box.setOutlineThickness(2.0f);
    box.setOutlineColor(sf::Color::Black);
}


void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box,window))
        enableStates(HOVERED);
    else
        disableStates(HOVERED);
}

void Button::update() {
    if(checkStates(HOVERED))
    {
        box.setFillColor(sf::Color::Blue);
        box.setOutlineColor(sf::Color::Blue);
    }
    else if(!checkStates(HOVERED))
    {
        text.setOutlineThickness(1.0);
        box.setOutlineColor(sf::Color::Black);
        box.setFillColor(sf::Color::White);
    }
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(text);
}

Snapshot Button::getSnapshot() const {
    return Snapshot();
}

void Button::applySnapshot(const Snapshot &snapshot) {

}

bool Button::isActive(ScreenType screen) const {
    return false;
}

void Button::setText(const std::string &_text) {
    this->text.setFont(Font::getFont(Font::arial));
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setOutlineThickness(1.0f);
    this->text.setCharacterSize(20);
    this->text.setString(_text);
}


void Button::setBoxSize(sf::Vector2f size) {
    box.setOutlineColor(sf::Color::Black);
    box.setSize(size);
}


sf::FloatRect Button::getGlobalBounds() {
    return box.getGlobalBounds();
}

void Button::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    Positioning::IsIn(box,text);
}

const sf::RectangleShape &Button::getBox() const {
    return box;
}
