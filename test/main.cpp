#include <iostream>
#include "A.h"
using namespace std;

int main() {
    A a;
    A b;
    for(int i=0; i<a.size()+1;i++)
    {
        a[i] = i;
    }
    std::cout << a << std::endl;

    b=a;

    std::cout << b << std::endl;

    A c(a);
    std::cout << c << std::endl;

    for (int i = 0; i < a.size(); ++i) {
        a[i] = i*10;
    }
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}
