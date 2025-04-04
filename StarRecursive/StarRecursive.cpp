//
// Created by hoben on 4/5/2023.
//

#include "StarRecursive.h"

void stars(int num, int spaces)
{
    if(num<= 0)
        return;
    else
    {
        stars(num/2, spaces);
        std::cout << std::string(spaces, ' ');
        std::cout << std::string(num, '*')<<std::endl;
        std::cout << std::endl;
        stars(num/2, spaces + num/2);
    }
}
