//
// Created by Ben Ho on 12/6/2023.
//

#include "NameTag.h"

NameTag::NameTag() {
    box.setOutlineThickness(1.0f);
    box.setOutlineColor(sf::Color::Black);
    box.setSize({65,20});
}

void NameTag::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void NameTag::update() {
    Positioning::IsIn(box,title);
}

void NameTag::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(title);
}

Snapshot NameTag::getSnapshot() const {
    return Snapshot();
}

void NameTag::applySnapshot(const Snapshot &snapshot) {

}


void NameTag::setPosition(const sf::Vector2f& position) {
    box.setPosition(position);
    Positioning::IsIn(box,title);

}

void NameTag::setName(const std::string &name) {
    title.setString(name);
    title.setFont(Font::getFont(Font::arial));
    title.setCharacterSize(20);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(1.0f);
}

void NameTag::setLabelSize(sf::Vector2f size) {
    box.setSize(size);
}

sf::RectangleShape &NameTag::getBox() {
    return box;
}

std::string NameTag::getTitle() const {
    return title.getString();
}

bool NameTag::isActive(ScreenType screen) const {
    return false;
}

sf::Text &NameTag::getTitle() {
    return title;
}
