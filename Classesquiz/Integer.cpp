//
// Created by hoben on 2/28/2023.
//

#include "Integer.h"

Integer::Integer() {
    number = 0;
}

Integer::Integer(int number):number(number) {
}


Integer operator+(const Integer &obj1, const Integer &obj2) {
    return{obj1.number + obj2.number};
}

std::istream &operator>>(std::istream &in, Integer& x) {
    in >> x.number;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Integer& x) {
    out << x.number;
    return out;
}


