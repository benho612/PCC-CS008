//
// Created by hoben on 2/1/2023.
//
#include "function.h"
Coordinate midpoint(const Coordinate& point1, const Coordinate&point2){
    Coordinate midpt = {(point1.x + point2.x)/2,(point1.y + point2.y)/2};
    return midpt;
}

void print(const Coordinate &coordinate) {
    std::cout<<"(" << coordinate.x << "," << coordinate.y << ")";
}

