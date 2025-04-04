#include <iostream>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window({720, 420, 32}, "sfml_project");
    window.setFramerateLimit(60);
    sf::CircleShape circle;
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Red);
    float xSpeed = 2.0, ySpeed = 2.0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (xSpeed + circle.getPosition().x > (window.getSize().x - circle.getRadius()*2) || circle.getPosition().x < 0) {
            xSpeed = -1 * xSpeed;
        }
        if (ySpeed + circle.getPosition().y > (window.getSize().y - circle.getRadius()*2) || circle.getPosition().y < 0) {
            ySpeed  = -1 * ySpeed ;
        }
        circle.move(xSpeed,ySpeed);

        window.clear();

        window.draw(circle);

        window.display();

    }
    return 0;
}
