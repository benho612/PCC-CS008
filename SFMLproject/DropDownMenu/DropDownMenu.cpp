//
// Created by hoben on 11/13/2023.
//

#include <iostream>
#include "DropDownMenu.h"

DropDownMenu::DropDownMenu()
{

}


void DropDownMenu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    itemList.eventHandler(window,event);
    inputBox.eventHandler(window,event);

    for (int i = 0; i < itemList.size(); ++i) {
        if(MouseEvents<sf::RectangleShape>::mouseClicked(itemList.getItemList(i).getItem(),window))
            enableStates(static_cast<statesEnum>(CLICKEDBOX1 + i));
        else
            disableStates(static_cast<statesEnum>(CLICKEDBOX1 + i));

    }

    if(MouseEvents<sf::RectangleShape>::mouseClicked(inputBox.getInputBox(),window))
    {
        enableStates(CLICKEDINPUTBOX);
        oldPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    }
    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window,event))
        disableStates(CLICKEDINPUTBOX);


    if(MouseEvents<sf::RectangleShape>::draggedOver(inputBox.getInputBox(),window,event))
    {
        newPos = (sf::Vector2f) sf::Mouse::getPosition(window);
        enableStates(DRAGGING);
    }



}

void DropDownMenu::update() {
    inputBox.update();
    itemList.update();
    setItemListPosition();
    setSameSizeAsInputBox();


    for (int i = 0; i < itemList.size(); ++i) {
        if(checkStates(static_cast<statesEnum>(CLICKEDBOX1 + i)))
        {
            inputBox.setString(itemList.getItemList(i).getString());
        }
    }
    /*if(checkStates(DRAGGING))
    {
        inputBox.getInputBox().move(newPos - oldPos);
        inputBox.setTextAndCursorPosition();
        oldPos = newPos;
    }*/
}

void DropDownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    if(checkStates(CLICKEDINPUTBOX))
        window.draw(itemList);
}

Snapshot DropDownMenu::getSnapshot() const {
}

void DropDownMenu::applySnapshot(const Snapshot &snapshot) {

}

void DropDownMenu::setItemListPosition() {
    Positioning::Under(inputBox,itemList);
}

void DropDownMenu::setSameSizeAsInputBox() {
    sf::Vector2f size = inputBox.getSize();
    float outlineThickness = inputBox.getOutlineThickness();
    itemList.setSize(size);
    itemList.setOutlineThickness(outlineThickness);
}

void DropDownMenu::push_back(const std::string &string) {
    itemList.push_back(string);
}

void DropDownMenu::setPosition(const sf::Vector2f &position) {
    inputBox.setPosition(position);
}

sf::FloatRect DropDownMenu::getGlobalBounds() const {
    return inputBox.getGlobalBounds();
}

bool DropDownMenu::isActive(ScreenType screen) const {
    return false;
}

void DropDownMenu::AlwaysDisplayingTheFirstItem() {
    if(!itemList.empty())
        inputBox.setString(itemList.getItemList(0).getString());
}
