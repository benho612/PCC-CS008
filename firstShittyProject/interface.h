//
// Created by Ben Ho on 9/3/2023.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

class interface {
public:
    interface();
private:
    int rows, cols;
public:
    int getRows() const;
    int getCols() const;
};


#endif //INTERFACE_H
