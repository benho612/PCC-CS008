//
// Created by Ben Ho on 10/22/2023.
//

#ifndef TYPING_FONT_H
#define TYPING_FONT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class Font {
public:
    enum FontEnum {arial, BloodMoon, last_Font};
    static sf::Font& getFont(FontEnum _font);
private:
    static void LoadFromFile(FontEnum _font);
    static std::string getFilePath(FontEnum _font);
    static std::unordered_map<FontEnum, sf::Font> font;
};


#endif //TYPING_FONT_H
