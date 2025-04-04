//
// Created by Ben Ho on 12/8/2023.
//

#ifndef SFMLPROJECT_MULTIPLAYER_H
#define SFMLPROJECT_MULTIPLAYER_H

#include <SFML/Network.hpp>
#include "../Interface/GUIComponent.h"
#include "../TextInputBox/InputBox.h"
#include "../Button.h"
#include "Server.h"
#include "Client.h"
#include "../FileTree/FileTree.h"

class Multiplayer:public GUIComponent,public States {
public:
    Multiplayer();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

private:
    Server server;
    Client client;
    std::vector<Button> buttonList;
    sf::Text text;
    InputBox inputBox;
    sf::Text text1;
    InputBox inputBox1;
};


#endif //SFMLPROJECT_MULTIPLAYER_H
