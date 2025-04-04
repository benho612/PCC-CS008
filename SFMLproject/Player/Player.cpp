//
// Created by Ben Ho on 12/5/2023.
//

#include "Player.h"
#include "../Interface/Application.h"

Player::Player():isMainCharacter(false)
{

};

Player::Player(const std::string &name):isMainCharacter(false) {
    playerName.setName(name);
}

void Player::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        Application::switchScreen(ScreenType::Pause);
    }
    if (isMainCharacter)
    {
        playerSprite.eventHandler(window,event);
    }
    playerName.eventHandler(window,event);
}

void Player::update() {
    if (isMainCharacter)
        playerSprite.update();

    playerName.update();
    Positioning::Above(playerSprite.getSprite(),playerName.getBox());
}

void Player::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(playerSprite);
    window.draw(playerName);
}

Snapshot Player::getSnapshot() const {
    return Snapshot();
}

void Player::applySnapshot(const Snapshot &snapshot) {

}

bool Player::isActive(ScreenType screen) const {
    return false;
}

void Player::setPlayerName(const std::string &name) {
    playerName.setName(name);
}


sf::Vector2f Player::getPosition() {
    return playerSprite.getPosition();
}

void Player::setPosition(const sf::Vector2f &position) {
    playerSprite.setPosition(position);
    Positioning::Above(playerSprite.getSprite(),playerName.getBox());
    Positioning::IsIn(playerName.getBox(),playerName.getTitle());

}

std::string Player::getPlayerName() const {
    return playerName.getTitle();
}

bool Player::isMainCharacter1() const {
    return isMainCharacter;
}

void Player::setIsMainCharacter(bool isMainCharacter) {
    Player::isMainCharacter = isMainCharacter;
}

