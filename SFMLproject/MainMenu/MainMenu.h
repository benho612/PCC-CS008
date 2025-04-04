//
// Created by Ben Ho on 12/6/2023.
//

#ifndef SFMLPROJECT_MAINMENU_H
#define SFMLPROJECT_MAINMENU_H


#include "../Interface/GUIComponent.h"
#include "../Menu Bar/MenuBar.h"
#include "../Helper/Image.h"

class MainMenu: public GUIComponent{
public:
    MainMenu();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

private:
    MenuBar bar;
    sf::Vector2f windowSize = {1024,768};
    sf::Sprite background;
};


#endif //SFMLPROJECT_MAINMENU_H
