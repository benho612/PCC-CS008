//
// Created by Ben Ho on 10/22/2023.
//

#include "Letter.h"

Letter::Letter() = default;

Letter::Letter(const sf::String &string, const sf::Font &font, unsigned int characterSize)
                :sf::Text(string, font, characterSize){

}

Letter::Letter(char letter):Letter(letter, Font::getFont(Font::arial),30) {

}

char Letter::getLetter()const {
    return (char) *sf::Text::getString().begin();
}









