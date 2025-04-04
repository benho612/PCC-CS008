//
// Created by Ben Ho on 12/10/2023.
//

#ifndef SFMLPROJECT_SERVER_H
#define SFMLPROJECT_SERVER_H


#include "../Interface/GUIComponent.h"
#include "../Interface/Application.h"
#include "../Player/Player.h"
#include "../Testing/ParsingXML.h"
#include <SFML/Network.hpp>
#include <map>

class Server: public GUIComponent, public States {
public:
    Server();
    ~Server() override;
    void startListening(const std::string& id);
    void stopListening();
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    Snapshot getSnapshot() const override;
    void applySnapshot(const Snapshot& snapshot) override;
    bool isActive(ScreenType screen) const override;

private:
    ///game feature
    Player player;
    std::map<sf::TcpSocket*, Player> players;
    ParsingXML map;
    void createPlayer(sf::TcpSocket* clientSocket, const std::string& name, sf::Vector2f position);


    ///network feature
    bool isListening;
    sf::TcpListener listener;
    std::vector<sf::TcpSocket*> clients;
    sf::SocketSelector selector;
    unsigned short port = 53000;


    ///function
    void sending();
    void receiving();
    void checkForDisconnection();
    void handleNewConnections();
    void broadcastMessage(const std::string& playerName, const std::string& message, sf::TcpSocket* sender);
};


#endif //SFMLPROJECT_SERVER_H
