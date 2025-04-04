//
// Created by Ben Ho on 11/7/2023.
//

#include <iostream>
#include "Cursor.h"

Cursor::Cursor() {
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(1.0);
}

void Cursor::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Cursor::update() {
    if(cursorClock.getElapsedTime().asSeconds() > blinkInterval)
    {
        isCursorVisible = !isCursorVisible;
        cursorClock.restart();
    }
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(isCursorVisible)
        window.draw(cursor);
}

Snapshot Cursor::getSnapshot() const {
}

void Cursor::applySnapshot(const Snapshot &snapshot) {

}

void Cursor::setPosition(sf::Vector2f position) {
    cursor.setPosition(position);
}

void Cursor::setSize(sf::Vector2f position) {
    cursor.setSize(position);
}

bool Cursor::isActive(ScreenType screen) const {
    return false;
}
