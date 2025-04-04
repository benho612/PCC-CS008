//
// Created by hoben on 11/13/2023.
//

#ifndef SFMLPROJECT_ITEMLIST_H
#define SFMLPROJECT_ITEMLIST_H

#include "SFML/Graphics.hpp"
#include "../Interface/GUIComponent.h"
#include "Item.h"
#include "../Helper/Positioning.h"
class ItemList: public Item {
public:
    ///constructor
    ItemList();

    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///set & get object
    void setItemListPosition();
    void CenterText(const sf::RectangleShape& object, sf::Text &CenterObject);
    void setPosition(const sf::Vector2f & position);
    void setSize(const sf::Vector2f & size);
    void setOutlineThickness(float thickness);
    const Item &getItemList(int index) const;
    void push_back(const std::string& string);
    int size() const;
    bool empty() const;
private:
    std::vector<Item> itemList;
};


#endif //SFMLPROJECT_ITEMLIST_H
