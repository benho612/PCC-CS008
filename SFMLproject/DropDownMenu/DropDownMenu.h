//
// Created by hoben on 11/13/2023.
//

#ifndef SFMLPROJECT_DROPDOWNMENU_H
#define SFMLPROJECT_DROPDOWNMENU_H
#include "../TextInputBox/InputBox.h"

class DropDownMenu:public GUIComponent,public States {
public:
    ///constructor
    DropDownMenu();

    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///set&get object
    void setPosition(const sf::Vector2f & position);
    void setItemListPosition();
    void setSameSizeAsInputBox();
    void push_back(const std::string& string);
    sf::FloatRect getGlobalBounds() const;
    void AlwaysDisplayingTheFirstItem();
private:
    ItemList itemList;
    InputBox inputBox;
    sf::Vector2f oldPos;
    sf::Vector2f newPos;
};


#endif //SFMLPROJECT_DROPDOWNMENU_H
