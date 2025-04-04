//
// Created by Ben Ho on 10/22/2023.
//

#include "Font.h"

std::unordered_map<Font::FontEnum, sf::Font> Font::font;

sf::Font &Font::getFont(FontEnum _font) {
    Font::LoadFromFile(_font);
    return font[_font];
}

void Font::LoadFromFile(Font::FontEnum _font) {
    font[_font].loadFromFile(getFilePath(_font));

}

std::string Font::getFilePath(Font::FontEnum _font) {
    switch(_font)
    {
        case arial:
            return "arial.ttf";
        case BloodMoon:
            return "BloodMoon-Regular.ttf";
        case last_Font:
            break;
    }
}
