//
// Created by hoben on 2/1/2023.
//

#include "test.h"

void midpointDriver() {
    char answer;
    Coordinate point1, point2;
    do{
        std::cout<<"Enter the X coordinate:";
        std::cin>>point1.x >> point2.x;
        std::cout<<"Enter the Y coordinate:";
        std::cin>>point1.y >> point2.y;
        print(midpoint(point1, point2));
        std::cout<<"Wanna try again (Y/N)";
        std::cin>>answer;
    }while(answer == tolower('y'));
}
