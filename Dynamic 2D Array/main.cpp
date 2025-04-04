#include "twoDArray.h"
int main() {
    srand(time(0));
    twoDArray test1(5,5);
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML window");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            test1.eventHandler(window, event);
        }
        window.clear();
        //test1.draw(window, sf::RenderStates());
        window.draw(test1);
        window.display();
    }
    return 0;
}
