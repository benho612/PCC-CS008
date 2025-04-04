//
// Created by hoben on 11/16/2023.
//

#include "MenuBar.h"

MenuBar::MenuBar() {
}

void MenuBar::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto&i:menuBar)
        i.eventHandler(window,event);
}

void MenuBar::update() {
    for(auto&i:menuBar)
        i.update();
    setMenuBar();
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(auto& i: menuBar)
        window.draw(i);
}

Snapshot MenuBar::getSnapshot() const {
    return Snapshot();
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}

void MenuBar::setMenuBar() {
   for (int i = 0; i < menuBar.size()-1; ++i) {
        Positioning::horizontallyAlign(menuBar[i],menuBar.at(i+1));
    }
}

bool MenuBar::isActive(ScreenType screen) const {
    return false;
}

void MenuBar::push_back(const Menu& menu) {
    menuBar.push_back(menu);
}

void MenuBar::setFirstMenuPosition(sf::Vector2f position) {
    menuBar.at(0).setPosition(position);
}

Menu &MenuBar::getMenuBar(int index) {
    return menuBar.at(index);
}

void MenuBar::AlwaysDisplayingTheFirstItem() {
    for(auto& i:menuBar)
        i.AlwaysDisplayingTheFirstItem();
}
