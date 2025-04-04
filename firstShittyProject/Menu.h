//
// Created by Ben Ho on 9/3/2023.
//

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
class Menu {
public:
    void Display();
    void DisplayUserHistory();
    void LogIn();
    void LogOff();
    Menu();
    Menu(int rows, int cols);
    friend std::ostream& operator <<(std::ostream& os, const Menu& dt);
private:
    std::vector<std::vector<std::string>> sit;
    std::queue<std::string> searchHistory;
};


#endif //H
