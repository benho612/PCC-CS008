//
// Created by Ben Ho on 10/22/2023.
//

#ifndef TYPING_LETTER_H
#define TYPING_LETTER_H
#include <SFML/Graphics.hpp>
#include "../Font.h"
class Letter: public sf::Text {
public:

    Letter();
    Letter(char letter);
    Letter(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);
    char getLetter() const;
private:
    sf::Font font;

};


#endif //TYPING_LETTER_H
