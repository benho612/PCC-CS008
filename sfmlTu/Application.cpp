//
// Created by hoben on 3/29/2023.
//

#include "Application.h"

sf::RenderWindow Application::window;
 std::vector<Component*> Application::components;

void Application::run() {
    window.create({1024,720,30}, "name");
    window.setFramerateLimit(60);

while (window.isOpen())
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
        for(Component* c: components)
         c->eventHandler(window, event);
    }
    for(Component * c: components)
       c->update();

    window.clear();
    for(Component * c: components)
        window.draw(*reinterpret_cast<sf::Drawable*>(c));
    window.display();
}
}

void Application::addComponents(Component &component) {
    components.push_back(&component);
}
