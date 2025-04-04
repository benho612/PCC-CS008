//
// Created by hoben on 2/27/2023.
//

#ifndef STRUCTTESTING_A_H
#define STRUCTTESTING_A_H
#include <iostream>
class A {
private:
    int * arr;
public:
    A();
    A(const A& a);
    ~A();
    int size();
    int& operator[](unsigned int index);
    friend std::ostream& operator <<(std::ostream& out, const A& a);
    void operator=(const A& a);
};


#endif //STRUCTTESTING_A_H
