//
// Created by hoben on 10/31/2023.
//

#ifndef TYPING_GUICOMPONENT_H
#define TYPING_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "../SnapShot/SnapShotInterface.h"
#include "ScreenType.h"

class GUIComponent: public sf::Drawable, public SnapShotInterface {
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual bool isActive(ScreenType screen) const = 0; // Add this method

    virtual Snapshot getSnapshot() const = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;


};


#endif //TYPING_GUICOMPONENT_H
