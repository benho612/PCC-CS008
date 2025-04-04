//
// Created by Ben Ho on 11/7/2023.
//

#ifndef SFMLPROJECT_POSITIONING_H
#define SFMLPROJECT_POSITIONING_H

#include "SFML/Graphics.hpp"
class Positioning {
public:
    template <typename T, typename S>
    static void NextTo(const T& object, S&objectNextTo);

    template<typename T, typename S>
    static void horizontallyAlign(const T& object, S&objectHorizontallyAlign);

    template <typename T, typename S>
    static void IsIn(const T& object, S&objectIsIn);

    template <typename T, typename S>
    static void Under(const T& object, S&objectUnder);

    template <typename T, typename S>
    static void JustInTheBox(const T& object, S&objectInTheBox);

    template <typename T, typename S>
    static void Above(const T& object, S&objectAbove);



};



#include "Positioning.cpp"

#endif //SFMLPROJECT_POSITIONING_H
