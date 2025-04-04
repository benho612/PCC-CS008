//
// Created by hoben on 11/13/2023.
//

#ifndef SFMLPROJECT_INPUTBOX_H
#define SFMLPROJECT_INPUTBOX_H
#include "MultiText.h"
#include "../DropDownMenu/ItemList.h"
#include "Cursor.h"
class InputBox:public GUIComponent, public States {
public:
    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///set object
    void setTextAndCursorPosition();
    void setInputBox();
    void setPosition(const sf::Vector2f & position);
    void setString(const std::string& word);
    void setSize(const sf::Vector2f & size);
    void setCharacterSize(int size);
    ///get object
    std::string getString() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    float getOutlineThickness() const;
    const sf::RectangleShape &getInputBox() const;
    sf::RectangleShape& getInputBox();

    ///constructor
    InputBox();
private:
    Cursor cursor;
    sf::RectangleShape inputBox;
    MultiText multiText1;
};


#endif //SFMLPROJECT_INPUTBOX_H
