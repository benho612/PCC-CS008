//
// Created by Ben Ho on 12/10/2023.
//

#ifndef SFMLPROJECT_CLIENT_H
#define SFMLPROJECT_CLIENT_H


#include <SFML/Network.hpp>
#include <thread>
#include "../Interface/GUIComponent.h"
#include "../Player/Player.h"
#include "../Testing/ParsingXML.h"
#include "../TextInputBox/InputBox.h"

class Client: public GUIComponent, public States {
public:
    Client();
    ~Client();
    void connectToServer(const sf::IpAddress& serverAddress, unsigned short port,const std::string& id);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method
private:

    ///game features
    Player player;
    std::vector<Player> playerList;
    ParsingXML map;
    void createPlayer(const std::string& name, sf::Vector2f position);

    ///network features
    sf::TcpSocket socket;
    void sending();
    void receiving();

    void sendChatMessage(const std::string& message);
};


#endif //SFMLPROJECT_CLIENT_H
