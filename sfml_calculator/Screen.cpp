//
// Created by hoben on 10/12/2023.
//

#include "Screen.h"

Screen::Screen() {
    box.setPosition({50,50});
    box.setFillColor(sf::Color::White);
    box.setSize({200,100});
}

Screen::Screen(const sf::Vector2f &dimensions, sf::RenderWindow& window) {
    box.setPosition({static_cast<float>((window.getPosition().x - 500.00)),
                     static_cast<float>((window.getPosition().y - 200))    });
    box.setFillColor(sf::Color::White);
    box.setSize(dimensions);
}


void Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(typing);
    window.draw(button);
}

sf::Vector2f Screen::getPosition() const {
    return box.getPosition();
}

void Screen::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
}

sf::FloatRect Screen::getGlobalBounds() const {
    return box.getGlobalBounds();
}

sf::FloatRect Screen::getLocalBounds() const {
    return box.getLocalBounds();
}

void Screen::eventHAndler(sf::RenderWindow &renderWindow, sf::Event event) {
    typing.eventHAndler(renderWindow,event);

}

void Screen::update(float dt) {
    typing.update(0);
    Helper::centerText(box , typing);
}
