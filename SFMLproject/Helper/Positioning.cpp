//
// Created by Ben Ho on 11/7/2023.
//

#ifndef SFMLPROJECT_POSITIONING_CPP
#define SFMLPROJECT_POSITIONING_CPP

#include "Positioning.h"

template<typename T, typename S>
void Positioning::NextTo(const T& object, S &objectNextTo) {
    sf::FloatRect bounds = object.getGlobalBounds();

    objectNextTo.setPosition({bounds.left+ bounds.width +4, bounds.top});
}

template<typename T, typename S>
void Positioning::IsIn(const T &object, S &objectIsIn) {
    sf::FloatRect bounds = object.getGlobalBounds();
    objectIsIn.setPosition({(bounds.left + bounds.width / 2) - (objectIsIn.getGlobalBounds().width /2),
                            (bounds.top + bounds.height /2) - (objectIsIn.getGlobalBounds().height /2)});
}


template<typename T, typename S>
void Positioning::Under(const T &object, S &objectUnder) {
    sf::FloatRect bounds = object.getGlobalBounds();
    objectUnder.setPosition({bounds.left + 4, (bounds.top + bounds.height)+5});

}

template<typename T, typename S>
void Positioning::horizontallyAlign(const T &object, S &objectHorizontallyAlign) {
    sf::FloatRect bounds = object.getGlobalBounds();
    objectHorizontallyAlign.setPosition({bounds.left+ bounds.width +4, bounds.top+4});
}

template<typename T, typename S>
void Positioning::JustInTheBox(const T &object, S &objectInTheBox) {
    sf::FloatRect bounds = object.getGlobalBounds();
    objectInTheBox.setPosition({bounds.left+10 , bounds.top+4});
}


template<typename T, typename S>
void Positioning::Above(const T &object, S &objectAbove) {
    sf::FloatRect bounds = object.getGlobalBounds();
    objectAbove.setPosition({bounds.left, bounds.top - (bounds.height /2)});
}


#endif //SFMLPROJECT_POSITIONING_CPP