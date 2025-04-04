//
// Created by hoben on 10/16/2023.
//

#ifndef SFML_CALCULATOR_BUTTONS_H
#define SFML_CALCULATOR_BUTTONS_H
#include <vector>
#include "Button.h"
class Buttons : public Button {
public:
    Buttons();
    Buttons(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Vector2f getPosition() const;
    //void setPosition(const sf::Vector2f & position);
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;
    void eventHAndler(sf::RenderWindow& renderWindow, sf::Event event) ;
    void update(float dt);
private:
    std::vector <Button> buttons;

};


#endif //SFML_CALCULATOR_BUTTONS_H
