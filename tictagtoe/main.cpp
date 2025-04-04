#include <iostream>
#include "ticTacToe.h"
int main() {
    int choice;
    ticTacToe a;
    do{
        a.displayBoard();
        a.out();
        std::cin >> choice ;
        std::cout <<"\n";
        a.set(choice);
    } while(a.winCondition());
    a.displayBoard();
    a.result();
}
