//
// Created by hoben on 10/31/2023.
//

#include "States.h"

States::States() {
    for(int i = 0; i<LAST_STATES; i++)
    {
        states[static_cast<statesEnum>(i)] = false;
    }
}

void States::enableStates(statesEnum state) {
    states[state] = true;
}

void States::disableStates(statesEnum state) {
    states[state] = false;

}

void States::toggleStates(statesEnum state) {
    states[state] = !states[state];
}

bool States::checkStates(statesEnum state) const {
    return states.at(state);
}
