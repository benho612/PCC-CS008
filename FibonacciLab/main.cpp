#include <iostream>
#include "iterative.h"
#include "Recursive.h"
#include "Timer.h"

int main() {
    std::cout << fib(50) << std::endl;

    std::cout << iterative(50) << std::endl;
}