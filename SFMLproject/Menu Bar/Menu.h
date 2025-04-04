//
// Created by hoben on 11/16/2023.
//

#ifndef SFMLPROJECT_MENU_H
#define SFMLPROJECT_MENU_H


#include "../DropDownMenu/DropDownMenu.h"

class Menu: public GUIComponent, public States {
public:
    ///constructor
    Menu();
    Menu(const std::vector<std::string>& test);
    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///set&get object
    void setPosition(const sf::Vector2f & position);
    sf::FloatRect getGlobalBounds() const;
    void push_back(const std::string& string);
    void AlwaysDisplayingTheFirstItem();
private:
    DropDownMenu menu;
};


#endif //SFMLPROJECT_MENU_H
