//
// Created by hoben on 3/29/2023.
//

#ifndef SFMLTU_APPLICATION_H
#define SFMLTU_APPLICATION_H
#include <SFML/Graphics.hpp>
#include "Component.h"
#include <vector>
class Application {
private:
     static sf::RenderWindow window;
     static std::vector<Component*> components;
public:
    static void addComponents(Component& component);
    static void run();
};


#endif //SFMLTU_APPLICATION_H
