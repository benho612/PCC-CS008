//
// Created by hoben on 11/16/2023.
//

#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(const std::vector<std::string>& test) {
    for (const auto & i : test) {
        menu.push_back(i);
    }
}


void Menu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    menu.eventHandler(window,event);
}

void Menu::update() {
    menu.update();
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(menu);
}

Snapshot Menu::getSnapshot() const {
    return Snapshot();
}

void Menu::applySnapshot(const Snapshot &snapshot) {

}

void Menu::push_back(const std::string& string) {
    menu.push_back(string);
}

sf::FloatRect Menu::getGlobalBounds() const {
    return menu.getGlobalBounds();
}

void Menu::setPosition(const sf::Vector2f &position) {
    menu.setPosition(position);
}

bool Menu::isActive(ScreenType screen) const {
    return false;
}

void Menu::AlwaysDisplayingTheFirstItem() {
    menu.AlwaysDisplayingTheFirstItem();

}

