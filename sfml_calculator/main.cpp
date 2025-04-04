#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.h"
int main() {
   sf::VideoMode videoMode(1000,900,64);
   sf::RenderWindow window(videoMode,"Calculator");
   window.setFramerateLimit(60);

   Screen scene({static_cast<float>(window.getPosition().x - 100.00) ,
                 static_cast<float>(window.getPosition().y - 200.00)}
                 , window);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            scene.eventHAndler(window,event);
        }
        scene.update(0);
        window.clear();
        window.draw(scene);
        window.display();
    }
    return 0;
}
