//
// Created by hoben on 2/28/2023.
//

#ifndef CLASSESQUIZ_INTEGER_H
#define CLASSESQUIZ_INTEGER_H
#include <iostream>

class Integer {
private:
    int number;
public:
    Integer();
    Integer(int number);
    friend Integer operator +(const Integer& num1, const Integer& num2);
    friend std::ostream& operator <<(std::ostream& out, const Integer& x);
    friend std::istream& operator >>(std::istream& in, Integer& x);
};


#endif //CLASSESQUIZ_INTEGER_H
