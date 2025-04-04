//
// Created by Ben Ho on 12/6/2023.
//

#ifndef SFMLPROJECT_NAMETAG_H
#define SFMLPROJECT_NAMETAG_H


#include "../States/States.h"
#include "../Interface/GUIComponent.h"
#include "../Helper/Positioning.h"
class NameTag: public States, public GUIComponent {
public:
    NameTag();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    void setPosition(const sf::Vector2f & position);
    void setName(const std::string& name);
    void setLabelSize(sf::Vector2f size);
    sf::RectangleShape &getBox();
    sf::Text &getTitle();
    std::string getTitle() const;
    bool isActive(ScreenType screen) const; // Add this method

private:
    sf::RectangleShape box;
    sf::Text title;
};


#endif //SFMLPROJECT_NAMETAG_H
