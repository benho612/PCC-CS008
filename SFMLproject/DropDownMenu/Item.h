//
// Created by hoben on 11/13/2023.
//

#ifndef SFMLPROJECT_ITEM_H
#define SFMLPROJECT_ITEM_H
#include "SFML/Graphics.hpp"
#include "../Interface/GUIComponent.h"
#include "../Font.h"
#include "../Helper/Positioning.h"
#include "../Helper/MouseEvents.h"
#include "../States/States.h"

class Item: public GUIComponent, public States {
public:
    ///constructor
    Item();
    Item(const std::string& _item);

    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///change object
    void setBoxSize(const sf::Vector2f &size);
    void setOutlineThickness(float thickness);
    void setPosition(const sf::Vector2f & position);
    void setString(const std::string& word);

    ///return object element
    const sf::RectangleShape &getItem() const;
    const sf::Text &getText() const;
    sf::FloatRect getGlobalBounds() const;
    std::string getString() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;


private:
    sf::RectangleShape item;
    sf::Text text;
    sf::Font font;
};


#endif //SFMLPROJECT_ITEM_H
