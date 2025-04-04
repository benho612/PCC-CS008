//
// Created by Ben Ho on 11/7/2023.
//

#ifndef SFMLPROJECT_CURSOR_H
#define SFMLPROJECT_CURSOR_H

#include <chrono>
#include "SFML/Graphics.hpp"
#include "../Helper/MouseEvents.h"
#include "../Interface/GUIComponent.h"

class Cursor : public GUIComponent,public States {

public:
    Cursor();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const ;
    void applySnapshot(const Snapshot& snapshot);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f position);
    bool isActive(ScreenType screen) const; // Add this method

private:
    sf::RectangleShape cursor;
    sf::Clock cursorClock;
    bool isCursorVisible = true;
    float blinkInterval = 0.5f; // 500 milliseconds
};


#endif //SFMLPROJECT_CURSOR_H
