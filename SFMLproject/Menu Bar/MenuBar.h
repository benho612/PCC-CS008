//
// Created by hoben on 11/16/2023.
//

#ifndef SFMLPROJECT_MENUBAR_H
#define SFMLPROJECT_MENUBAR_H

#include "Menu.h"
class MenuBar: public GUIComponent, public States {
public:
    ///Constructor
    MenuBar();

    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///set&get object Function
    void push_back(const Menu& menu);
    void setFirstMenuPosition(sf::Vector2f position);
    Menu& getMenuBar(int index);
    void AlwaysDisplayingTheFirstItem();

private:
    void setMenuBar();
    std::vector<Menu> menuBar;
};


#endif //SFMLPROJECT_MENUBAR_H
