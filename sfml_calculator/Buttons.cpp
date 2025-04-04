//
// Created by hoben on 10/16/2023.
//

#include "Buttons.h"

Buttons::Buttons() {
    Button firstButton;
    buttons.emplace_back(firstButton);
    buttons[0].setPosition({100,100});
}

Buttons::Buttons(sf::RenderWindow &window) {
    Button firstButton;
    buttons.emplace_back(firstButton);
    buttons[0].setPosition({100,100});
}

void Buttons::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(const auto& i:buttons)
        window.draw(i);
}

sf::Vector2f Buttons::getPosition() const {
}

/*void Buttons::setPosition(const sf::Vector2f &position) {
}*/

sf::FloatRect Buttons::getGlobalBounds() const {
}

sf::FloatRect Buttons::getLocalBounds() const {
    return sf::FloatRect();
}

void Buttons::eventHAndler(sf::RenderWindow &renderWindow, sf::Event event) {

}

void Buttons::update(float dt) {

}


