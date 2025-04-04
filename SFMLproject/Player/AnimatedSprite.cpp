//
// Created by Ben Ho on 5/3/2023.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() {
    setup(Images::getImage(Images::walking),4,4);
}

AnimatedSprite::AnimatedSprite(sf::Texture&texture, int rows, int cols) {
    setup(texture, rows, cols);
}

void AnimatedSprite::animate() {
    if(clock.getElapsedTime().asMilliseconds() > time)
    {
        if (intRect.left >= width - intRect.width)
            intRect.left = 0;
        else
            intRect.left += intRect.width;
        clock.restart();
        sprite.setTextureRect(intRect);
    }
}

void AnimatedSprite::setup(sf::Texture&texture, int rows, int cols) {
    width = texture.getSize().x;
    sprite.setTexture(texture);
    setupIntRect(texture.getSize(), rows, cols);
}

void AnimatedSprite::setupIntRect(sf::Vector2u imgSize, int rows, int cols) {
    intRect.width = std::round(imgSize.x / cols);
    intRect.height = imgSize.y / rows;
    intRect.left = 0;
    intRect.top = 0;
    sprite.setTextureRect(intRect);
}

int AnimatedSprite::getTime() const {
    return time;
}

void AnimatedSprite::setTime(int time) {
    AnimatedSprite::time = time;
}

void AnimatedSprite::update() {
        animate();
}

void AnimatedSprite::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f veloctiy;
    if(sf::Keyboard::isKeyPressed(forwardKey))
    {
        changeDirection(BACK);
        veloctiy.x = 0;
        veloctiy.y = -speed;
    }
    else if(sf::Keyboard::isKeyPressed(leftKey))
    {
        changeDirection(LEFT);
        veloctiy.x = -speed;
        veloctiy.y = 0;
    }
    else if (sf::Keyboard::isKeyPressed(DownKey))
    {
        changeDirection(FORWARD);
        veloctiy.x = 0;
        veloctiy.y = speed;
    }
    else if (sf::Keyboard::isKeyPressed(rightKey))
    {
        changeDirection(RIGHT);
        veloctiy.x = speed;
        veloctiy.y = 0;
    }
    sprite.move(veloctiy);
}

void AnimatedSprite::changeDirection(directions direction) {
    intRect.top = intRect.height * static_cast<int>(direction);
}

float AnimatedSprite::getSpeed() const {
    return speed;
}

void AnimatedSprite::setSpeed(float speed) {
    AnimatedSprite::speed = speed;
}


void AnimatedSprite::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(sprite);
}

Snapshot AnimatedSprite::getSnapshot() const {
    return Snapshot();
}

void AnimatedSprite::applySnapshot(const Snapshot &snapshot) {

}

void AnimatedSprite::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

sf::Sprite &AnimatedSprite::getSprite()  {
    return sprite;
}

bool AnimatedSprite::isActive(ScreenType screen) const {
    //return screen == ScreenType::mainMenu;
}

sf::Vector2f AnimatedSprite::getPosition() {
    return sprite.getPosition();
}
