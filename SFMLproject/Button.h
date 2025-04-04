//
// Created by hoben on 12/6/2023.
//

#ifndef SFMLPROJECT_BUTTON_H
#define SFMLPROJECT_BUTTON_H


#include "Interface/GUIComponent.h"
#include "Helper/MouseEvents.h"
class Button: public GUIComponent, public States {
public:
    ///constuctor
    Button();
    Button(const std::string& _text);

    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method


    void setText(const std::string& _text);
    void setBoxSize(sf::Vector2f size);
    void setPosition(const sf::Vector2f & position);
    sf::FloatRect getGlobalBounds();

    const sf::RectangleShape &getBox() const;

private:
    sf::Text text;
    sf::RectangleShape box;

};


#endif //SFMLPROJECT_BUTTON_H
