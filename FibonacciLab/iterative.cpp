//
// Created by hoben on 4/4/2023.
//

#include "iterative.h"

unsigned int iterative(int nTerm){
    int x = 0, y = 1, z = 0;
    for (int i = 0; i < nTerm; ++i) {
        z = x + y;
        x = y;
        y = z;
    }
    return x;
}