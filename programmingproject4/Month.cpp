//
// Created by Ben Ho on 2/6/2023.
//

#include "Month.h"

Month::Month():first(0),second(0),third(0) {
}

Month::Month(char first, char second, char third):first(first),second(second),third(third){
//
}

char Month::getFirst() {
    return first;
}

char Month::getSecond() {
    return second;
}

char Month::getThird() {
    return third;
}


void Month::print()
{
    std::cout<<getFirst()<<getSecond()<<getThird()<<std::endl;
}

