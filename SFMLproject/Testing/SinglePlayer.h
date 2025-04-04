//
// Created by Ben Ho on 12/8/2023.
//

#ifndef SFMLPROJECT_SINGLEPLAYER_H
#define SFMLPROJECT_SINGLEPLAYER_H


#include "../Interface/GUIComponent.h"
#include "../Player/Player.h"
#include "ParsingXML.h"
#include "../TextInputBox/InputBox.h"

class SinglePlayer: public GUIComponent, public States {
public:
    SinglePlayer();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method
private:
    InputBox inputBox;
    Player player;
    ParsingXML map;
};


#endif //SFMLPROJECT_SINGLEPLAYER_H
