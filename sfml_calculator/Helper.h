//
// Created by hoben on 10/12/2023.
//

#ifndef SFML_CALCULATOR_HELPER_H
#define SFML_CALCULATOR_HELPER_H

#include <SFML/Graphics.hpp>
#include <cmath>
class Helper {
public:
    template <typename T, typename S>
    static void centerText(const T&obj, S& text);
};



#include "Helper.cpp"

#endif //SFML_CALCULATOR_HELPER_H
