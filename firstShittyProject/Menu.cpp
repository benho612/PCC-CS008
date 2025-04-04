//
// Created by Ben Ho on 9/3/2023.
//

#include "Menu.h"


Menu::Menu() = default;

Menu::Menu(int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        sit.emplace_back();
        for (int j = 0; j < cols; ++j) {
            sit[i].emplace_back("empty");
        }
    }
}

void Menu::Display() {
    std::cout<<"\nSTATUS\n";
    for (auto & i : sit) {
        for (const auto & j : i) {
            std::cout << j << " " << std::setw(5);
        }
        std::cout <<std::endl;
    }
}

void Menu::LogIn() {
    int tempRows, tempCols;
    std::string tempName;
    std::cout<<"Please enter your name to claim the sit\n";
    std::cin >> tempName;
    std::cout<<"Please enter which rows you wanna sit\n";
    std::cin >> tempRows;
    std::cout<<"Please enter which cols you wanna sit\n";
    std::cin >> tempCols;
    if(sit[tempRows-1][tempCols-1] == "empty")
    {
        sit[tempRows-1][tempCols-1] = tempName;
        searchHistory.push(tempName + " has claim rows " + std::to_string(tempRows) + " and cols " + std::to_string(tempCols));
        Display();
    }
    else
    {
        std::cout<<"\n This sit already occupied!!";
    }
}

void Menu::LogOff() {
    bool found = false;
    std::string name;
    std::cout<<"Enter your name\n";
    std::cin >> name;
    for (auto & i : sit) {
        for (auto & j : i) {
            if(j == name)
            {
                j = "empty";
                found = true;
                std::cout<<"logging out\n";
                searchHistory.push(name + " has logOut");
                Display();
                break;

            }
        }
    }
    if(!found)
        std::cout <<"\n Error couldn't find your name\n";

}

std::ostream &operator<<(std::ostream &os, const Menu &dt) {
    std::cout<<"\nSTATUS\n";
    for (auto & i : dt.sit) {
        for (const auto & j : i) {
            std::cout << j << " " << std::setw(5);
        }
        std::cout <<std::endl;
    }
    return os;
}

void Menu::DisplayUserHistory() {
    int i = 1;
    while (!searchHistory.empty()) {
        std::cout << i <<":"  <<searchHistory.front()<< "\n";
        i++;
        searchHistory.pop();
    }}





