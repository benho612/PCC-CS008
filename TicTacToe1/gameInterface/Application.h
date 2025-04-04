//
// Created by Ben Ho on 9/17/2023.
//

#ifndef TICTACTOE_APPLICATION_H
#define TICTACTOE_APPLICATION_H
#include "Component.h"

class Application: public Component {
public:
    void start();
    std::string getTitle();
    void addGame(Component& game);
private:
    void displayMenu();
    void startGame(int index);
    int getUserInput();
    std::vector<Component*> Game;



};


#endif //TICTACTOE_APPLICATION_H
