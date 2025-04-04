#include <iostream>
#include "Integer.h"
int main()

{
     Integer one(1);

     Integer two(2);

     Integer three;

     three = one + two;

     two = one + 1;

     std::cout << one << std::endl; // outputs 1

     std::cout << two << std::endl; // outputs 2

     std::cout << three << std::endl; // outputs 3

     std::cin >> three;

     std::cout << three << std::endl; // outputs whatever number the user entered;

     Integer * ptr;
     ptr = &three;
     std::cout << *ptr;
     *ptr = 7;
     Integer * p;
     p = new Integer[5];
     delete [] p;
     delete ptr;

     return 0;

}
