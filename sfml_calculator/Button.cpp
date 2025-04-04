//
// Created by hoben on 10/16/2023.
//

#include "Button.h"


void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(button);
}

sf::Vector2f Button::getPosition() const {
    return button.getPosition();
}

void Button::setPosition(const sf::Vector2f &position) {
    button.setPosition(position);
}

sf::FloatRect Button::getGlobalBounds() const {
    return button.getGlobalBounds();
}

sf::FloatRect Button::getLocalBounds() const {
    return button.getLocalBounds();
}

void Button::eventHAndler(sf::RenderWindow &renderWindow, sf::Event event) {

}

void Button::update(float dt) {

}

Button::Button() {
    button.setFillColor(sf::Color::Green);
    button.setRadius(50);
}

Button::Button(sf::RenderWindow &window) {
    button.setFillColor(sf::Color::Green);
    button.setRadius(50);
    button.setPosition(window.getPosition().x - 50, window.getPosition().y - 50);
}
