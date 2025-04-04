//
// Created by Ben Ho on 10/22/2023.
//

#ifndef TYPING_MULTITEXT_H
#define TYPING_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include <iterator>
#include <list>
#include "Letter.h"
#include "../Interface/GUIComponent.h"
#include "../Helper/KeyboardShortcut.h"
#include "../States/States.h"
#include "../SnapShot/SnapShotInterface.h"
#include "../Helper/MouseEvents.h"
#include "../History/History.h"
#include "../TextInputBox/Cursor.h"

class MultiText: public GUIComponent, public States, public MouseEvents<Letter>{
public:
    ///constructor
    MultiText();
    MultiText(unsigned int characterSize);

    ///
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    ///function
    void push_back(const Letter& letter);
    void addCharacter();
    void seperateAddCharacter(char letter);
    float getAdvance(const Letter& letter);

    ///iterator
    typedef std::list<Letter>::iterator iterator;
    typedef std::list<Letter>::const_iterator const_iterator;
    iterator begin();
    iterator end() ;
    const_iterator cbegin() const ;
    const_iterator cend() const ;

    ///snapshot
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    void setHistoryNode();
    std::string getString() const;
    bool isActive(ScreenType screen) const; // Add this method

    ///set object
    void setPosition(const sf::Vector2f & position);
    void setString(const std::string &word);
    void setCharacterSize(int size);
    ///return object
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;
    const std::list<Letter> &getLetters() const;
    std::list<Letter> &getLetters();
    unsigned int getCharacterSize() const;
    sf::Vector2f getCurPosition() const;
    bool isEmpty();
    void setActive(bool active);
private:
    std::list<Letter> letters;
    unsigned int characterSize = 0;
    std::string inputText;
    sf::Font font;
    sf::Vector2f _curPosition;
    sf::Glyph _glyph;
    bool isOperator(char ch);
    bool isActiving = false;
};


#endif //TYPING_MULTITEXT_H
