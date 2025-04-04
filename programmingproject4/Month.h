//
// Created by Ben Ho on 2/6/2023.
//

#ifndef PROGRAMMINGPROJECT4_MONTH_H
#define PROGRAMMINGPROJECT4_MONTH_H
#include <iostream>

class Month {
private:
    char first, second, third;
public:
    char getFirst();
    char getSecond();
    char getThird();
    Month();
    Month(char first, char second, char third);
    void print();
};

#endif //PROGRAMMINGPROJECT4_MONTH_H
