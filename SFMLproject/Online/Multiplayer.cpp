//
// Created by Ben Ho on 12/8/2023.
//

#include "Multiplayer.h"

Multiplayer::Multiplayer() {
    text.setFont(Font::getFont(Font::arial));
    text.setString("Enter Your ID");
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.0f);
    text1.setFont(Font::getFont(Font::arial));
    text1.setString("Enter IP address");
    text1.setOutlineColor(sf::Color::Black);
    text1.setOutlineThickness(2.0f);
    buttonList.emplace_back("Host Game");
    buttonList.emplace_back("Join Game");

    for(auto&i:buttonList)
        i.setBoxSize({200,50});

    buttonList[0].setPosition({300,300});
    buttonList[1].setPosition({300,350});


    text.setPosition(200,550);
    inputBox.setPosition({400,550});

    text1.setCharacterSize(20);
    text1.setPosition(150,450);
    inputBox1.setPosition({400,450});


}

void Multiplayer::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Application::switchScreen(ScreenType::Pause);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(buttonList.at(0).getBox(),window) && !inputBox.getString().empty())
    {
        Application::addComponent(server);
        Application::switchScreen(ScreenType::UserChooseServer);
        server.startListening(inputBox.getString());
    }
    if(MouseEvents<sf::RectangleShape>::mouseClicked(buttonList.at(1).getBox(),window) && !inputBox.getString().empty())
    {
        sf::IpAddress IpAddress = inputBox1.getString();
        Application::addComponent(client);
        Application::switchScreen(ScreenType::UserChooseClient);
        client.connectToServer(IpAddress,53000,inputBox.getString());
    }


    for (auto &i: buttonList)
        i.eventHandler(window, event);

    inputBox.eventHandler(window,event);
    inputBox1.eventHandler(window,event);
}

void Multiplayer::update() {
    for(auto&i:buttonList)
        i.update();

    inputBox.update();
    inputBox1.update();
}

void Multiplayer::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    window.draw(text);
    window.draw(inputBox1);
    window.draw(text1);
    for(auto&i:buttonList)
        window.draw(i);
}

Snapshot Multiplayer::getSnapshot() const {
    return Snapshot();
}

void Multiplayer::applySnapshot(const Snapshot &snapshot) {

}

bool Multiplayer::isActive(ScreenType screen) const {
    return screen == ScreenType::server_Client_Mode;
}
