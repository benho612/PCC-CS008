//
// Created by Ben Ho on 11/19/2023.
//

#ifndef SFMLPROJECT_FILEITEM_H
#define SFMLPROJECT_FILEITEM_H


#include "../Helper/Image.h"
#include "../Interface/GUIComponent.h"
#include "../Helper/Positioning.h"
#include "../Font.h"

class FileItem : public GUIComponent, public States
{
public:
    ///Constructors
    FileItem();
    FileItem(Images::Image icon, const std::string& text, sf::Vector2f size, sf::Vector2f position);

    ///GUIComponent
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method

    ///set & get Object
    sf::FloatRect getGlobalBounds() const;
    void setSize(sf::Vector2f size);
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::RectangleShape getBox();
    void setPosition(sf::Vector2f pos);


    //uses an enum to change the icon to a folder or file
    void setIcon(Images::Image _icon);
    void setString(const std::string& _text);
    void reSizeIcon(const sf::Vector2f& size);
    std::string getText();
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    sf::Sprite icon;

    void horizontallyAlign(const sf::Sprite& object, sf::Text&objectHorizontallyAlign);

    void JustInTheBox(const sf::RectangleShape &object, sf::Sprite &objectInTheBox);

};



#endif //SFMLPROJECT_FILEITEM_H
