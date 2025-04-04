//
// Created by Ben Ho on 4/3/2023.
//

#ifndef POKERANALYSIS_APPLICATION_H
#define POKERANALYSIS_APPLICATION_H

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
    static int getWindowLeftBound();
};


#endif //POKERANALYSIS_APPLICATION_H
