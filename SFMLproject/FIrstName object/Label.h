//
// Created by Ben Ho on 11/7/2023.
//

#ifndef SFMLPROJECT_LABEL_H
#define SFMLPROJECT_LABEL_H


#include "../Interface/GUIComponent.h"

class Label: public GUIComponent {
public:
    Label();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);

    const sf::Text &getLabel1() const;
    const sf::Text &getLabel2();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f & position);
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;
private:
    sf::Text label1;
    sf::Text label2;
};


#endif //SFMLPROJECT_LABEL_H
