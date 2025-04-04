//
// Created by hoben on 11/13/2023.
//

#include "ItemList.h"

ItemList::ItemList() {
    //Item item1("12345");
    //Item item2("123456");
    //itemList.emplace_back(item1);
    //itemList.emplace_back(item2);
}

void ItemList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (auto & i : itemList) {
        i.eventHandler(window,event);
    }

}

void ItemList::update() {
    for (auto & i : itemList) {
        i.update();
    }
    setItemListPosition();
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!checkStates(CURSORCLICKED))
    {
        for(auto& i:itemList)
            window.draw(i);
    }
}

Snapshot ItemList::getSnapshot() const {

}

void ItemList::applySnapshot(const Snapshot &snapshot) {

}

void ItemList::setItemListPosition() {
    for (int i = 0; i < itemList.size()-1; ++i) {
        Positioning::Under(itemList.at(i),itemList.at(i+1));
    }
    for (const auto & j : itemList) {
        CenterText(j.getItem(), const_cast<sf::Text &>(j.getText()));

    }
}

void ItemList::CenterText(const sf::RectangleShape& object, sf::Text &CenterObject) {
    sf::FloatRect bounds = object.getGlobalBounds();
    CenterObject.setPosition({(bounds.left + bounds.width / 2) - (CenterObject.getGlobalBounds().width /2),
                            (bounds.top + bounds.height /2) - (CenterObject.getGlobalBounds().height /2)});
}

void ItemList::setPosition(const sf::Vector2f &position) {
    itemList.at(0).setPosition(position);
}

void ItemList::setSize(const sf::Vector2f &size) {
    for (auto & i : itemList) {
        i.setBoxSize(size);
    }
}

void ItemList::setOutlineThickness(float thickness) {
    for (auto & i : itemList) {
        i.setOutlineThickness(thickness);
    }
}

const Item &ItemList::getItemList(int index) const {
    return itemList[index];
}

void ItemList::push_back(const std::string &string) {
    Item item(string);
    itemList.emplace_back(item);
}

int ItemList::size() const {
    return itemList.size();
}

bool ItemList::isActive(ScreenType screen) const {
    return Item::isActive(screen);
}

bool ItemList::empty() const {
    return itemList.empty();
}

