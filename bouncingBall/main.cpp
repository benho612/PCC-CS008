#include <iostream>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window({720,420,32}, "sfml_project");
    window.setFramerateLimit(60);
    sf::CircleShape circle;
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Red);
    float xSpeed = 2.0, ySpeed = 2.0;
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        //This function makes the ball move in the window
        bounce(window, circle);

        window.clear(sf::Color::Black);

        window.draw(circle);

        window.display();

    }
    }
    return 0;

}
