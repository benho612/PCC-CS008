//
// Created by hoben on 12/6/2023.
//

#include "PausingScreen.h"
#include "../Interface/Application.h"
#include "../Helper/Positioning.h"
#include "../Helper/Image.h"


PausingScreen::PausingScreen() {
    background.setTexture(Images::getImage(Images::PausingBackGround));

    Button Button1("Resume");
    Button Button2("Return to Main Menu");
    Button Button3("Exit");
    buttonList.push_back(Button1);
    buttonList.push_back(Button2);
    buttonList.push_back(Button3);

    for(auto&i:buttonList)
        i.setBoxSize({200,50});
    setButtonListPosition();
}

void PausingScreen::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (auto &i: buttonList)
        i.eventHandler(window, event);


    if (event.type == sf::Event::MouseButtonPressed) {
        if (buttonList.at(0).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
            Application::switchScreen(ScreenType::singlePlayer);
        else if(buttonList.at(1).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
        {
            Application::switchScreen(ScreenType::mainMenu);
        }
        else if (buttonList.at(2).getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            window.close();
            exit(0);
        }
    }
}

void PausingScreen::update() {
    for(auto&i:buttonList)
        i.update();
}

void PausingScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    for(auto&i:buttonList)
        window.draw(i);
}

Snapshot PausingScreen::getSnapshot() const {
    return Snapshot();
}

void PausingScreen::applySnapshot(const Snapshot &snapshot) {

}

bool PausingScreen::isActive(ScreenType screen) const {
    return screen == ScreenType::Pause;
}

void PausingScreen::setButtonPosition() {

}

void PausingScreen::setButtonListPosition() {
    buttonList[0].setPosition({300,300});
    buttonList[1].setPosition({300,350});
    buttonList[2].setPosition({300,400});


}
