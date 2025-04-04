//
// Created by hoben on 10/12/2023.
//

#ifndef SFML_CALCULATOR_FONT_H
#define SFML_CALCULATOR_FONT_H

#include <SFML/Graphics.hpp>
class Font {
public:
    static sf::Font& getFont(const std::string& FileName);
private:
    static sf::Font font;
};


#endif //SFML_CALCULATOR_FONT_H
