//
// Created by Ben Ho on 12/6/2023.
//

#include "MainMenu.h"
#include "../Interface/Application.h"

void MainMenu::eventHandler(sf::RenderWindow &window, sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed) {
        // Check if the mouse is over the start button
        if (bar.getMenuBar(0).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            Application::switchScreen(ScreenType::singlePlayer);
        else if(bar.getMenuBar(1).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            Application::switchScreen(ScreenType::server_Client_Mode);
        else if(bar.getMenuBar(2).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            Application::switchScreen(ScreenType::Option);
        else if (bar.getMenuBar(3).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            window.close();
    }
    bar.eventHandler(window,event);
}

void MainMenu::update() {
    bar.update();
}

void MainMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(bar);
}

Snapshot MainMenu::getSnapshot() const {
    return Snapshot();
}

void MainMenu::applySnapshot(const Snapshot &snapshot) {

}

MainMenu::MainMenu() {
    background.setTexture(Images::getImage(Images::MainMenuBackGround));
    bar.push_back(Menu({"SinglePlayer"}));
    bar.push_back(Menu({"MultiPlayer"}));
    bar.push_back(Menu({"Option"}));
    bar.push_back(Menu({"Exit"}));
    bar.AlwaysDisplayingTheFirstItem();
    bar.setFirstMenuPosition({windowSize.x/2-400,windowSize.y/2+100});

}

bool MainMenu::isActive(ScreenType screen) const {
    return screen == ScreenType::mainMenu;

}
