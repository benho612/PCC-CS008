//
// Created by hoben on 4/6/2023.
//

#ifndef SFMLTU_ANIMATEDSPRITE_H
#define SFMLTU_ANIMATEDSPRITE_H
#include "SFML/Graphics.hpp"
#include "Component.h"
#include <iostream>
#include <cmath>

enum directions {FORWARD, LEFT, RIGHT, BACK};

class AnimatedSprite: public Component, public sf::Sprite{
private:
    sf::Clock clock;
    sf::IntRect intRect;
    int time = 250;
    void setup(sf::Texture& texture, int rows, int cols);
    void setupIntRect(sf::Vector2u imgSize, int rows, int cols);
    float width, height;
    float speed;
    sf::Keyboard::Key forwardKey = sf::Keyboard::Up, leftKey = sf::Keyboard::Left,
    rightKey = sf::Keyboard::Right, DownKey = sf::Keyboard::Down, Up, down, left, right;
public:
    void setUp(sf::Keyboard::Key up);

    void setDown(sf::Keyboard::Key down);

    void setLeft(sf::Keyboard::Key left);

    void setRight(sf::Keyboard::Key right);

    void setForwardKey(sf::Keyboard::Key forwardKey);

    void setLeftKey(sf::Keyboard::Key leftKey);

    void setRightKey(sf::Keyboard::Key rightKey);

    void setDownKey(sf::Keyboard::Key downKey);

    float getSpeed() const;

    void setSpeed(float speed);

    int getTime() const;

    void setTime(int time);

    AnimatedSprite();

    AnimatedSprite(sf::Texture& texture, int rows, int cols);

    void animate();

    void update();

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;

    void changeDirection(directions direction);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFMLTU_ANIMATEDSPRITE_H
