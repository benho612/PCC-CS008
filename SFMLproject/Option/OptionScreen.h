//
// Created by Ben Ho on 12/12/2023.
//

#ifndef SFMLPROJECT_OPTIONSCREEN_H
#define SFMLPROJECT_OPTIONSCREEN_H


#include "../States/States.h"
#include "../Interface/GUIComponent.h"
#include "../FileTree/FileTree.h"

class OptionScreen: public GUIComponent,public States {
public:
    OptionScreen();
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method
private:
    sf::Sprite background;
    FileTree tree;
};


#endif //SFMLPROJECT_OPTIONSCREEN_H
