//
// Created by Ben Ho on 9/17/2023.
//

#include <vector>
#include <iostream>
#include "Application.h"

void Application::start() {

    displayMenu();
    startGame(getUserInput());
}

void Application::addGame(Component &game) {
    Game.push_back(&game);
}

void Application::displayMenu() {
    std::cout <<"Menu \n ";
    for (int i = 0; i < Game.size(); ++i) {
        std::cout << (i+1) << ": " << Game[i]->getTitle() << std::endl;
    }
}

int Application::getUserInput() {
    int index;
    std::cout <<"Select a game. \n";
    std::cin >> index;
    return (index -1);
}

void Application::startGame(int index) {
    Game[index]->start();
}

std::string Application::getTitle() {
    return "";
}
