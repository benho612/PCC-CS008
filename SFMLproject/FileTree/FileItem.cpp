//
// Created by Ben Ho on 11/19/2023.
//

#include "FileItem.h"
#include "../Helper/MouseEvents.h"

FileItem::FileItem() = default;

FileItem::FileItem(Images::Image icon, const std::string& text, sf::Vector2f size, sf::Vector2f position) {
    box.setOutlineThickness(2.0);
    box.setOutlineColor(sf::Color::Black);
    box.setPosition(position);
    setSize(size);
    setIcon(icon);
    setString(text);
    reSizeIcon({box.getSize().y,box.getSize().y});
    JustInTheBox(this->box,this->icon);
    horizontallyAlign(this->icon,this->text);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(text);
    window.draw(icon);
}

void FileItem::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box,window))
        enableStates(HOVEREDBOX);
    else
        disableStates(HOVEREDBOX);
}

sf::FloatRect FileItem::getGlobalBounds() const {
    return box.getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {
    return box.getSize();
}

sf::Vector2f FileItem::getPosition() const {
    return box.getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {

    box.setPosition(pos);
    JustInTheBox(this->box,this->icon);
    horizontallyAlign(this->icon,this->text);
}

void FileItem::setIcon(Images::Image _icon) {
    icon.setTexture(Images::getImage(_icon));
}

void FileItem::update() {


    if(checkStates(HOVEREDBOX))
    {
        text.setOutlineThickness(2.0);
        box.setFillColor(sf::Color::Blue);
    }
    else
    {
        text.setOutlineThickness(1.0);
        box.setFillColor(sf::Color::White);
    }

}

Snapshot FileItem::getSnapshot() const {

}

void FileItem::applySnapshot(const Snapshot &snapshot) {

}

void FileItem::setString(const std::string& _text) {
    this->text.setFont(Font::getFont(Font::arial));
    this->text.setString(_text);
    this->text.setOutlineThickness(1.0);
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setCharacterSize(20);
}

void FileItem::setSize(sf::Vector2f size) {
    box.setSize(size);

}

void FileItem::reSizeIcon(const sf::Vector2f& size) {
    icon.setScale({1,1});
    float scaleX = size.x/ (float ) this->icon.getTexture()->getSize().x;
    float scaleY = size.y/ (float ) this->icon.getTexture()->getSize().y;
    icon.setScale({scaleX,scaleY});
}

sf::RectangleShape FileItem::getBox() {
    return box;
}

std::string FileItem::getText() {
    return text.getString();
}

void FileItem::horizontallyAlign(const sf::Sprite &object, sf::Text &objectHorizontallyAlign) {
    objectHorizontallyAlign.setPosition({object.getGlobalBounds().left+ object.getGlobalBounds().width +4, object.getGlobalBounds().top+4});
}

void FileItem::JustInTheBox(const sf::RectangleShape &object, sf::Sprite &objectInTheBox) {
    sf::FloatRect bounds = object.getGlobalBounds();
    objectInTheBox.setPosition({bounds.left , bounds.top});
}

bool FileItem::isActive(ScreenType screen) const {
    return false;
}


