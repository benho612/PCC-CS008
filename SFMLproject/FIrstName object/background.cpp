//
// Created by Ben Ho on 11/7/2023.
//

#include <iostream>
#include "background.h"

void background::eventHandler(sf::RenderWindow &window, sf::Event event) {

    inputBox.eventHandler(window,event);

    if(MouseEvents<sf::RectangleShape>::mouseClicked(inputBox.getInputBox(),window))
        enableStates(CLICKED);
    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window,event))
        disableStates(CLICKED);

    cursor.eventHandler(window,event);
}

void background::update() {
    Positioning::NextTo(label,inputBox.getInputBox());
    inputBox.update();
    cursor.update();

}

void background::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label.getLabel1());
    window.draw(inputBox);
    window.draw(cursor);
}

Snapshot background::getSnapshot() const {
}

void background::applySnapshot(const Snapshot &snapshot) {

}


background::background() = default;




