//
// Created by Ben Ho on 12/8/2023.
//

#include "SinglePlayer.h"

SinglePlayer::SinglePlayer() {
    player.setPlayerName("Jimmy");
    player.setIsMainCharacter(true);
    inputBox.setPosition({100,600});
}

void SinglePlayer::eventHandler(sf::RenderWindow &window, sf::Event event) {
    map.eventHandler(window,event);
    player.eventHandler(window,event);
    inputBox.eventHandler(window,event);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        toggleStates(HIDDEN);

}

void SinglePlayer::update() {
    map.update();
    player.update();
    inputBox.update();
}

void SinglePlayer::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(map);
    window.draw(player);
    if(!checkStates(HIDDEN))
        window.draw(inputBox);
}

Snapshot SinglePlayer::getSnapshot() const {
    return Snapshot();
}

void SinglePlayer::applySnapshot(const Snapshot &snapshot) {

}

bool SinglePlayer::isActive(ScreenType screen) const {
    return screen == ScreenType::singlePlayer;
}


