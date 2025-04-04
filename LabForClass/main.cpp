#include <iostream>
#include "Date.h"
#include "Holiday.h"
int main() {

    Date d(1, 5, 2021);
    Date d2;
    std::cout << d.getDate("YY-M-d") <<"\n";
    std::cout << d.getDate("MM d, YY")<<"\n";
    std::cout << d.getDate("m/d")<<"\n";
    d = d - 1;
    d2 = d;
    std::cout << d;
    std::cout << d2;
    std::cout <<d.getDate();
    return 0;
}
