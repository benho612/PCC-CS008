//
// Created by hoben on 10/31/2023.
//

#ifndef TYPING_STATES_H
#define TYPING_STATES_H
#include "StatesEnum.h"
#include <SFML/Graphics.hpp>

class States{
private:
    std::map<statesEnum, bool> states;
public:
    States();
    bool checkStates(statesEnum state) const;
    void enableStates(statesEnum state);
    void disableStates(statesEnum state);
    void toggleStates(statesEnum state);
};


#endif //TYPING_STATES_H
