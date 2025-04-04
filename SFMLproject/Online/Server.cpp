//
// Created by Ben Ho on 12/10/2023.
//

#include <iostream>
#include "Server.h"

Server::Server(): isListening(false) {
    listener.setBlocking(false);
    player.setIsMainCharacter(true);
}

Server::~Server() {
    stopListening();
}

void Server::stopListening() {
    isListening = false;

    listener.close();
    for (auto& client : clients) {
        if (client) {
            selector.remove(*client);
            client->disconnect();
            delete client;
        }
    }
    clients.clear();
}


void Server::eventHandler(sf::RenderWindow &window, sf::Event event) {
    player.eventHandler(window,event);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Application::switchScreen(ScreenType::Pause);
}

void Server::update() {
    player.update();

    handleNewConnections();
    checkForDisconnection();
    sending();
    receiving();

}

void Server::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(map);
    window.draw(player);
    if(!players.empty())
        for(auto&i:players)
            window.draw(i.second);
}

Snapshot Server::getSnapshot() const {
    return {};
}

void Server::applySnapshot(const Snapshot &snapshot) {

}

bool Server::isActive(ScreenType screen) const {
    return screen == ScreenType::UserChooseServer;
}

void Server::checkForDisconnection() {
    for (auto iter = clients.begin(); iter != clients.end();) {
        sf::TcpSocket* client = *iter;

        if (selector.isReady(*client)) {
            sf::Packet packet;
            if (client->receive(packet) == sf::Socket::Disconnected) {
                std::cout << client->getRemoteAddress().toString() << " has disconnected" << std::endl;
                players.erase(client);
                selector.remove(*client);
                client->disconnect();
                delete client;
                iter = clients.erase(iter);
            } else {
                ++iter;
            }
        } else {
            ++iter;
        }
    }
}

void Server::startListening(const std::string& id) {
    player.setPlayerName(id);

    std::cout << "You are the server\n";

    if (!isListening) {
        listener.listen(port);
        selector.add(listener);
        isListening = true;
    }
}


void Server::receiving() {
    std::vector<sf::TcpSocket*> disconnectedClients;

    for (auto &client : clients) {
        if (selector.isReady(*client)) {
            sf::Packet incomingPacket;
            sf::Socket::Status status = client->receive(incomingPacket);

            if (status == sf::Socket::Done) {
                sf::Vector2f p2Position;
                std::string playerName;
                std::string message;
                if (incomingPacket >> playerName >> p2Position.x >> p2Position.y)
                {
                    auto it = players.find(client);
                    if (it != players.end()) {
                        it->second.setPosition(p2Position);
                    } else
                    {
                        createPlayer(client,playerName,p2Position);
                    }
                }
            } else if (status == sf::Socket::Disconnected) {
                disconnectedClients.push_back(client);
            }
        }
    }

    // Now safely remove disconnected clients
    for (auto &client : disconnectedClients) {
        std::cout << client->getRemoteAddress().toString() << " has disconnected" << std::endl;
        players.erase(client);
        selector.remove(*client);
        client->disconnect();
        clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
        delete client;
    }
}

void Server::sending() {
    for (auto &client: clients) {
        if (selector.isReady(*client)) {
            auto it = players.find(client);
            if (it != players.end()) {
                sf::Packet packetToSend;
                packetToSend << player.getPlayerName() << player.getPosition().x << player.getPosition().y;
                sf::Socket::Status status = client->send(packetToSend);

                if (status == sf::Socket::Done) {

                } else if (status == sf::Socket::NotReady) {

                } else {
                    // Handle other statuses (e.g., Disconnected, Error)
                }
            }
        }
    }
}
void Server::createPlayer(sf::TcpSocket* clientSocket, const std::string &name, sf::Vector2f position) {
    Player tempPlayer(name);
    tempPlayer.setPosition(position);
    players[clientSocket] = tempPlayer;
}

void Server::handleNewConnections() {
    if (selector.wait(sf::milliseconds(0))) {
        if (selector.isReady(listener)) {
            auto *socket = new sf::TcpSocket();
            if (listener.accept(*socket) == sf::Socket::Done) {
                sf::Packet incomingPacket;
                if (socket->receive(incomingPacket) == sf::Socket::Done) {
                    sf::Vector2f p2Position;
                    std::string ID, text;
                    incomingPacket >> ID >> p2Position.x >> p2Position.y >> text;
                    std::cout << ID << " has connected to server " << text << std::endl;
                    createPlayer(socket, ID, p2Position);
                    clients.push_back(socket);
                    selector.add(*socket);
                } else {
                    selector.remove(*socket);
                    socket->disconnect();
                    delete socket; // Only delete if not added to clients
                }
            } else {
                delete socket; // Only delete if not added to clients
            }
        }
    }
}

void Server::broadcastMessage(const std::string& playerName, const std::string &message, sf::TcpSocket *sender) {
    for (auto &client : clients) {
        if (client != sender) { // Don't send back to the sender
            sf::Packet packetToSend;
            packetToSend <<playerName << message;
            client->send(packetToSend);
        }
    }
    std::cout << playerName<<": " << message << std::endl; // Server console output
}





