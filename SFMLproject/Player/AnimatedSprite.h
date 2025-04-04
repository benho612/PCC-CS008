//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_ANIMATEDSPRITE_H
#define OSUMANIA_ANIMATEDSPRITE_H


#include "SFML/Graphics.hpp"
#include <iostream>
#include "../States/States.h"
#include "../Helper/Image.h"
#include "../Interface/GUIComponent.h"
#include <cmath>

enum directions {FORWARD, LEFT, RIGHT, BACK};

class AnimatedSprite: public GUIComponent, public States{
private:
    sf::Sprite sprite;
    sf::Clock clock;
    sf::IntRect intRect;
    int time = 100;
    void setup(sf::Texture& texture, int rows, int cols);
    void setupIntRect(sf::Vector2u imgSize, int rows, int cols);
    float width, height;
    float speed = 5.0f;
    sf::Keyboard::Key forwardKey = sf::Keyboard::Up, leftKey = sf::Keyboard::Left, rightKey = sf::Keyboard::Right, DownKey = sf::Keyboard::Down;

public:

    ///getter & setter
    float getSpeed() const;
    void setSpeed(float speed);
    int getTime() const;
    void setTime(int time);
    sf::Vector2f getPosition();
    void setPosition(const sf::Vector2f & position);

    void animate();
    void changeDirection(directions direction);
    sf::FloatRect getGlobalBounds() const;
    sf::Sprite &getSprite();

    ///Constructor
    AnimatedSprite();
    AnimatedSprite(sf::Texture& texture, int rows, int cols);


    ///GUI Component
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

};



#endif //OSUMANIA_ANIMATEDSPRITE_H
