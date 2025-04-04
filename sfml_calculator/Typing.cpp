//
// Created by hoben on 10/11/2023.
//

#include "Typing.h"

Typing::Typing() {
    text.setFont(Font::getFont("arial.ttf"));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

sf::Vector2f Typing::getPosition() const {
    return text.getPosition();
}

void Typing::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

sf::FloatRect Typing::getGlobalBounds() const {
    return text.getGlobalBounds();
}

sf::FloatRect Typing::getLocalBounds() const {
    return text.getLocalBounds();
}

void Typing::eventHAndler(sf::RenderWindow &renderWindow, sf::Event event) {
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128)
        {
            if (event.text.unicode == '\b' && !inputText.empty())
            {
                inputText.pop_back();
            }
            else if(event.text.unicode == 13 && !inputText.empty())
            {
                result = RPN::PostFixEval(inputText);
                inputText.clear();
                inputText += (std::to_string(result));
            }
            else if (event.text.unicode != '\b' && event.text.unicode != 13)
            {
                inputText += static_cast<char>(event.text.unicode);
            }
        }
    }
}

void Typing::update(float dt) {
    text.setString(inputText);
}
