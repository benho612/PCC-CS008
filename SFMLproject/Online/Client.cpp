//
// Created by Ben Ho on 12/10/2023.
//

#include "Client.h"
#include "../Interface/Application.h"

Client::Client() {
    player.setIsMainCharacter(true);
}

Client::~Client() {
    socket.disconnect();
}

void Client::eventHandler(sf::RenderWindow &window, sf::Event event) {
    player.eventHandler(window,event);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Application::switchScreen(ScreenType::Pause);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        toggleStates(HIDDEN);
}

void Client::update() {
    player.update();
    receiving();
    sending();

}

void Client::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(map);
    window.draw(player);

    if(!playerList.empty())
        for(auto&i:playerList)
            window.draw(i);

}

Snapshot Client::getSnapshot() const {
    return {};
}

void Client::applySnapshot(const Snapshot &snapshot) {

}

bool Client::isActive(ScreenType screen) const {
    return screen == ScreenType::UserChooseClient;
}

void Client::connectToServer(const sf::IpAddress &serverAddress, unsigned short port, const std::string& id) {
    socket.setBlocking(false);
    player.setPlayerName(id);
    if (socket.connect(serverAddress, port) == sf::Socket::Done) {
        sf::Packet sentPacket;
        std::cout << "Connected to " << serverAddress <<std::endl;
        sentPacket << id << player.getPosition().x << player.getPosition().y << "First Time Connecting";
        socket.send(sentPacket);
    }
    else
        std::cout <<"Fail to connect to " <<serverAddress.toString() <<std::endl;
}



void Client::sending() {
    sf::Packet sentPacket;
    sentPacket << player.getPlayerName() << player.getPosition().x << player.getPosition().y;
    sf::Socket::Status status = socket.send(sentPacket);
    if (status == sf::Socket::Done) {
    } else if (status == sf::Socket::NotReady) {
        // Socket not ready for sending, try again later
    }
}
void Client::receiving() {
    sf::Packet incomingPacket;
    sf::Socket::Status status = socket.receive(incomingPacket);

    if (status == sf::Socket::Done) {
        std::string playerName, message;
        sf::Vector2f p2Position;
        if (incomingPacket >> playerName >> p2Position.x >> p2Position.y) {
            auto it = std::find_if(playerList.begin(), playerList.end(), [&](const Player& p) {
                return p.getPlayerName() == playerName;
            });
            if (it != playerList.end()) {
                it->setPosition(p2Position);
            } else {
                createPlayer(playerName, p2Position);
            }
        }

    } else if (status == sf::Socket::NotReady) {
        // No data to receive, try again later
    } else if (status == sf::Socket::Disconnected) {
        // Handle disconnection
        std::cout << "Disconnected from server." << std::endl;
        // Additional cleanup or state change as needed
    }
}

void Client::createPlayer(const std::string &name, sf::Vector2f position) {
    Player tempPlayer(name);
    tempPlayer.setPosition(position);
    playerList.push_back(tempPlayer);
}

void Client::sendChatMessage(const std::string& message) {
    ///TODO
    sf::Packet packetToSend;
    packetToSend << player.getPlayerName() << message;
    socket.send(packetToSend);
}







