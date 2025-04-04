//
// Created by Ben Ho on 9/17/2023.
//

#ifndef TICTACTOE_COMPONENT_H
#define TICTACTOE_COMPONENT_H


#include <string>

class Component {
public:
    virtual void start() = 0;
    virtual std::string getTitle() = 0;
};


#endif //TICTACTOE_COMPONENT_H
