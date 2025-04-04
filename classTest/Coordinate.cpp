//
// Created by hoben on 2/2/2023.
//

#include "Coordinate.h"

template<typename T>
T Coordinate<T>::getX() {
    return x;
}

template<typename T>
Coordinate<T>::Coordinate():x(0),y(0) {
}

template<typename T>
Coordinate<T>::Coordinate(T x, T y):x(x),y(y) {
}


