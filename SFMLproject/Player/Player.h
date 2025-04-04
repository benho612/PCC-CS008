//
// Created by Ben Ho on 12/5/2023.
//

#ifndef SFMLPROJECT_PLAYER_H
#define SFMLPROJECT_PLAYER_H


#include "../Interface/GUIComponent.h"
#include "AnimatedSprite.h"
#include "NameTag.h"

class Player: public States, public GUIComponent {
public:
    Player();
    Player(const std::string& name);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    void setPlayerName(const std::string& name);
    std::string getPlayerName() const;
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition();
    bool isMainCharacter1() const;
    void setIsMainCharacter(bool isMainCharacter);

private:
    bool isMainCharacter;
    AnimatedSprite playerSprite;
    NameTag playerName;
};


#endif //SFMLPROJECT_PLAYER_H
