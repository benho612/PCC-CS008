//
// Created by hoben on 12/6/2023.
//

#ifndef SFMLPROJECT_PAUSINGSCREEN_H
#define SFMLPROJECT_PAUSINGSCREEN_H


#include "../Interface/GUIComponent.h"
#include "../Button.h"
#include "../Online/Client.h"
#include "../Online/Server.h"

class PausingScreen: public GUIComponent {
public:
    PausingScreen();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method
    void setButtonPosition();
    void setButtonListPosition();
private:
    sf::Sprite background;
    std::vector<Button> buttonList;
};


#endif //SFMLPROJECT_PAUSINGSCREEN_H
