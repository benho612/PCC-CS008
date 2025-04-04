//
// Created by Ben Ho on 12/8/2023.
//

#ifndef SFMLPROJECT_PARSINGXML_H
#define SFMLPROJECT_PARSINGXML_H
#include <iostream>
#include <vector>
#include <sstream>
#include "pugixml.hpp"
#include "../Interface/GUIComponent.h"
#include "Layer.h"
#include <SFML/Graphics.hpp>
#include "../Helper/Image.h"
class ParsingXML:public GUIComponent {
public:
    ParsingXML();
    void Parse();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot() const;
    void applySnapshot(const Snapshot& snapshot);
    bool isActive(ScreenType screen) const; // Add this method
private:
    std::vector<Layer> layers;
    Layer layer;
    int mapWidth, mapHeight, tileWidth, tileHeight;
    std::map<int, sf::Sprite> tileSprites;

};



#endif //SFMLPROJECT_PARSINGXML_H
