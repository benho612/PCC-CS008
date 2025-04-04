//
// Created by Ben Ho on 12/12/2023.
//

#include "OptionScreen.h"
#include "../Interface/Application.h"

OptionScreen::OptionScreen() {
    tree.push("Color","Blue");
    tree.push("Color", "Red");
    tree.push("Red","Red-1");
    tree.push("Red","Red-2");
    tree.push("Blue","Blue-1");
    tree.push("Blue","Blue-2");
}

void OptionScreen::update() {
    tree.update();
}

void OptionScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(tree);
}

Snapshot OptionScreen::getSnapshot() const {
    return Snapshot();
}

void OptionScreen::applySnapshot(const Snapshot &snapshot) {

}

bool OptionScreen::isActive(ScreenType screen) const {
    return screen == ScreenType::Option;
}

void OptionScreen::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Application::switchScreen(ScreenType::Pause);

    tree.eventHandler(window,event);


}
