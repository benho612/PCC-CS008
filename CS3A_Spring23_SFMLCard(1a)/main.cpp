#include <SFML/Graphics.hpp>
#include "Card.h"

int main() {
   Card c (KING,HEARTS);
    sf::RenderWindow window({1000, 1000, 32}, "sfml_project");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        c.draw(window,sf::RenderStates());
        window.display();

    }
    return 0;
}
