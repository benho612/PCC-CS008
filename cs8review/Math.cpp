//
// Created by hoben on 9/5/2023.
//

#include "Math.h"

double Math::divide(double x, double y) {
    if (y == 0)
    {
        throw DivideByZeroException("num is " + std::to_string(y));
    }
    return x/y;
}

double Math::squareRoot(double num) {
    if(num < 0)
    {
        throw NegativeNumberException("num is" + std::to_string(num));
    }
    return sqrt(num);
}

