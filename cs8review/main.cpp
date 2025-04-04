#include <iostream>
#include "Math.h"

int main() {
    Math e;
    double divide, squareRoot;
    try
    {
        divide = e.divide(5,2);
        squareRoot = e.squareRoot(5);
    }
    catch (DivideByZeroException e)
    {
        std::cout <<  e.what() << std::endl;
    }
    catch (NegativeNumberException e)
    {
        std::cout <<  e.what() << std::endl;
    }
    catch (...)
    {

    }
}
