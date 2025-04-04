//
// Created by Ben Ho on 11/7/2023.
//

#ifndef SFMLPROJECT_BACKGROUND_H
#define SFMLPROJECT_BACKGROUND_H

#include "../Interface/GUIComponent.h"
#include "../Helper/Positioning.h"
#include "Label.h"
#include "../Helper/MouseEvents.h"
#include "../TextInputBox/InputBox.h"

class background: public GUIComponent, public MouseEvents<sf::RectangleShape>,public States {
public:
    void eventHandler(sf::RenderWindow &window, sf::Event event);

    void update();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    Snapshot getSnapshot() const;

    void applySnapshot(const Snapshot &snapshot);

    background();

private:
    Label label;
    InputBox inputBox;
    Cursor cursor;
};

#endif //SFMLPROJECT_BACKGROUND_H
