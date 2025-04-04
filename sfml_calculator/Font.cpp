//
// Created by hoben on 10/12/2023.
//

#include "Font.h"
sf::Font Font::font;

sf::Font& Font::getFont(const std::string& FileName) {
    font.loadFromFile(FileName);
    return font;
}
