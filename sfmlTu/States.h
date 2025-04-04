//
// Created by hoben on 4/11/2023.
//

#ifndef SFMLTU_STATES_H
#define SFMLTU_STATES_H
#include <map>

enum states_enum{
    MOVING,
    LAST_STATE
};
class States {
private:
    std::map<states_enum, bool> states;
public:
    States();
    void enable_state(states_enum state);
    void disable_state(states_enum state);
    bool check_state(states_enum state);
    void toggle_state(states_enum state);
};


#endif //SFMLTU_STATES_H
