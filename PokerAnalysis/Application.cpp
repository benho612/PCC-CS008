//
// Created by hoben on 3/29/2023.
//

#include "Application.h"

sf::RenderWindow Application::window;
std::vector<Component*> Application::components;

void Application::run() {
    window.create({1920,1080,30}, "PokerAnalysis");
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        for(Component * c: components)
            window.draw(*c);
        window.display();
    }
}

void Application::addComponents(Component &component) {
    components.push_back(&component);
}

int Application::getWindowLeftBound() {
    return window.getPosition().x;
}
