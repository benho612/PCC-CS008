#include <iostream>
#include "Menu.h"
#include "interface.h"

int main() {
    interface Interface;
    Menu a(Interface.getRows(),Interface.getCols());
    int choice;
    while(true) {
        std::cout<<"MENU \n0) Exit\n1) Login\n2) Logoff\n3) Display\n4) User History\nEnter your choice: ";
        std::cin>>choice;
        switch(choice) {
            case 0:
                std::cout<<"\nExited";
                exit(1);
            case 1:
                a.LogIn();
                std::cout<<std::endl;
                break;
            case 2:
                a.LogOff();
                std::cout<<std::endl;
                break;
            case 3:
                std::cout << a;
                std::cout<<std::endl;
                break;
            case 4:
                a.DisplayUserHistory();
                std::cout<<std::endl;
                break;
            default:
                std::cout<<"\n Enter a correct choice!!";
                break;
        }
    }
}
