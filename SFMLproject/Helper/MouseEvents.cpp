//
// Created by hoben on 11/6/2023.
//
#ifndef TYPING_MOUSEEVENTS_cpp
#define TYPING_MOUSEEVENTS_cpp

#include <iostream>
#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::mouseClicked(const T &object, sf::RenderWindow &window) {
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(object.getGlobalBounds().contains(mPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        return true;
    else
        return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        return true;
    else
        return false;
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if(clicks==2)
    {
        clicks = 0;
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    if(clicks ==3)
    {
        clicks = 0;
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    static bool isDragging = false;
    if (MouseEvents<T>::mouseClicked(object, window))
    {
        isDragging = true;
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        isDragging = false; // Stop dragging
    }
    return isDragging;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(object.getGlobalBounds().contains(mPos))
        return true;
    else
        return false;
}

template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {

}

#endif //TYPING_MOUSEEVENTS_cpp