//
// Created by hoben on 10/18/2023.
//

#include "TeddyBear.h"

bool TeddyBear::bears(int n) {
    if(n == 42)
        return true;
    else if( n < 42)
        return false;

    if (n % 2 == 0 )
        if (bears(n/2))
            return true;

    if(n % 3 == 0 || n % 4 == 0)
        if((n % 10) * ((n/10) % 10) != 0 && (bears(n - (n % 10) * ( (n/10) % 10))))
            return true;

    if(n % 5 == 0)
        if(bears(n-42))
            return true;

    return false;
}
