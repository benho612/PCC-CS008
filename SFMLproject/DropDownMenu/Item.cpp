//
// Created by hoben on 11/13/2023.
//

#include "Item.h"

Item::Item() {
    text.setFont(Font::getFont(Font::arial));
    Positioning::IsIn(item,text);
}

Item::Item(const std::string &_item) {
    text.setFont(Font::getFont(Font::arial));
    text.setString(_item);
    Positioning::IsIn(item,text);
}

void Item::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(item,window))
        enableStates(HOVEREDBOX);
    else
        disableStates(HOVEREDBOX);
}

void Item::update() {
    if(checkStates(HOVEREDBOX))
    {
        text.setOutlineThickness(2.0);
        item.setFillColor(sf::Color::Blue);
    }
    else
    {
        text.setOutlineThickness(1.0);
        item.setFillColor(sf::Color::White);
    }
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(item);
    window.draw(text);

}

Snapshot Item::getSnapshot() const {

}

void Item::applySnapshot(const Snapshot &snapshot) {

}

void Item::setBoxSize(const sf::Vector2f &size) {
    item.setOutlineColor(sf::Color::Black);
    item.setSize(size);
}

const sf::RectangleShape &Item::getItem() const {
    return item;
}

sf::FloatRect Item::getGlobalBounds() const {
    return item.getGlobalBounds();
}

void Item::setPosition(const sf::Vector2f &position) {
    item.setPosition(position);
}

void Item::setOutlineThickness(float thickness) {
    item.setOutlineThickness(thickness);
}

std::string Item::getString() const {
    return text.getString();
}

void Item::setString(const std::string &word) {
    text.setString(word);
}

const sf::Text &Item::getText() const {
    return text;
}

sf::Vector2f Item::getSize() const {
    return item.getSize();
}

sf::Vector2f Item::getPosition() const {
    return item.getPosition();
}

bool Item::isActive(ScreenType screen) const {
    return false;
}


