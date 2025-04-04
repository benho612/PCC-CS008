//
// Created by hoben on 10/12/2023.
//


#ifndef SFML_CALCULATOR_HELPER_CPP
#define SFML_CALCULATOR_HELPER_CPP

#include "Helper.h"

template<typename T, typename S>
void Helper::centerText(const T &constObj, S& obj) {
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({(bounds.left + bounds.width / 2) - (obj.getGlobalBounds().width /2),
                     (bounds.top + bounds.height /2 - (obj.getGlobalBounds().height /2 ))
    });

}


#endif //SFML_CALCULATOR_HELPER_CPP
