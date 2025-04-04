//
// Created by hoben on 11/13/2023.
//

#include "InputBox.h"

void InputBox::eventHandler(sf::RenderWindow &window, sf::Event event) {
    cursor.eventHandler(window,event);

    multiText1.eventHandler(window,event);

    if(MouseEvents<sf::RectangleShape>::mouseClicked(inputBox,window))
    {
        enableStates(TYPING);
        enableStates(CURSORCLICKED);
        enableStates(CLICKED);

        multiText1.setActive(true);
    }

    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window,event))
    {
        disableStates(TYPING);
        disableStates(CURSORCLICKED);
        disableStates(CLICKED);

        multiText1.setActive(false);
    }


}

void InputBox::update() {
    multiText1.update();
    cursor.update();
    setTextAndCursorPosition();


}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    window.draw(multiText1);
    if(checkStates(CLICKED))
        window.draw(cursor);
}

Snapshot InputBox::getSnapshot() const {
    return Snapshot();
}

void InputBox::applySnapshot(const Snapshot &snapshot) {

}

void InputBox::setTextAndCursorPosition() {
    sf::Vector2f typingPos = inputBox.getPosition();
    typingPos.y -= (float) this->multiText1.getCharacterSize() / 50.f;
    this->multiText1.setPosition(typingPos);
    multiText1.setString(multiText1.getString());

    this->cursor.setSize({1,static_cast<float>(multiText1.getCharacterSize())});
    if(!multiText1.isEmpty())
        cursor.setPosition({multiText1.getGlobalBounds().left + multiText1.getGlobalBounds().width, typingPos.y+5});
    else
        cursor.setPosition({typingPos.x+5,typingPos.y+5});
}


InputBox::InputBox() {
    setInputBox();
}

void InputBox::setInputBox() {
    inputBox.setPosition({400,200});
    inputBox.setOutlineThickness(4.0);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setSize({200,50});
}

void InputBox::setPosition(const sf::Vector2f &position) {
    inputBox.setPosition(position);
}

sf::FloatRect InputBox::getGlobalBounds() const {
    return inputBox.getGlobalBounds();
}

sf::Vector2f InputBox::getSize() const {
    return inputBox.getSize();
}

float InputBox::getOutlineThickness() const {
    return inputBox.getOutlineThickness();
}

void InputBox::setString(const std::string &word) {
    multiText1.setString(word);
}

const sf::RectangleShape &InputBox::getInputBox() const {
    return inputBox;
}

sf::RectangleShape &InputBox::getInputBox() {
    return inputBox;
}

bool InputBox::isActive(ScreenType screen) const {
    return false;
}

sf::Vector2f InputBox::getPosition() const {
    return inputBox.getPosition();
}

std::string InputBox::getString() const {
    return multiText1.getString();
}

void InputBox::setSize(const sf::Vector2f &size) {
    inputBox.setSize(size);
}

void InputBox::setCharacterSize(int size) {
    multiText1.setCharacterSize(size);
}


