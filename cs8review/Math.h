//
// Created by hoben on 9/5/2023.
//

#ifndef CS8REVIEW_MATH_H
#define CS8REVIEW_MATH_H

#include <iostream>
#include <cmath>
#include "DivideByZeroException.h"
#include "NegativeNumberException.h"

class Math {
public:
    double divide(double x, double y);
    double squareRoot(double num);

};


#endif //CS8REVIEW_MATH_H
