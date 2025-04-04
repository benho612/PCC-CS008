//
// Created by hoben on 4/4/2023.
//

#include "Recursive.h"

int recursive(int first, int second, int nTerm)
{
    if(nTerm <= 1 )
        return first;
    return(recursive(second, first+second, nTerm-1));
}

unsigned int fib(int n)
{
    if(n == 0)
        return 0;
    else if(n<3)
        return 1;
    return fib(n - 1) + fib( n - 2);
}