#include <iostream>
#include "TeddyBear.h"
int main() {
    if(TeddyBear::bears(10000))
        std::cout << "True" << std::endl;
    else
        std::cout <<"False" << std::endl;


    return 0;
}
