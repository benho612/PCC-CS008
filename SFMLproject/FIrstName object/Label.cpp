//
// Created by Ben Ho on 11/7/2023.
//

#include "Label.h"

void Label::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Label::update() {

}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label1);
}

Snapshot Label::getSnapshot() const {
}

void Label::applySnapshot(const Snapshot &snapshot) {

}

Label::Label() {
    label1.setFont(Font::getFont("arial.ttf"));
    label1.setCharacterSize(24); // Set the font size
    label1.setFillColor(sf::Color::Blue); // Set the text color
    label1.setString("First Name"); // Set the text content
    label1.setPosition({50,50});

}

const sf::Text & Label::getLabel1() const {
    return label1;
}

const sf::Text &Label::getLabel2() {
    return label2;
}

sf::FloatRect Label::getGlobalBounds() const {
    return label1.getGlobalBounds();
}

sf::FloatRect Label::getLocalBounds() const {
    return label1.getLocalBounds();
}

sf::Vector2f Label::getPosition() const {
    return label1.getPosition();
}

void Label::setPosition(const sf::Vector2f &position) {
    label1.setPosition(position);
}


