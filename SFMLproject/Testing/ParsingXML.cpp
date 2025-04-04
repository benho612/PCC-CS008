//
// Created by Ben Ho on 12/8/2023.
//

#include "ParsingXML.h"

void ParsingXML::Parse() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("Testing/map.tmx");

    if (!result) {
        std::cerr << "Loading TMX file failed: " << result.description() << std::endl;
    }

    pugi::xml_node mapNode = doc.child("map");

     mapWidth = mapNode.attribute("width").as_int();
     mapHeight = mapNode.attribute("height").as_int();
     tileWidth = mapNode.attribute("tilewidth").as_int();
     tileHeight = mapNode.attribute("tileheight").as_int();

    for (pugi::xml_node tilesetNode = mapNode.child("tileset"); tilesetNode; tilesetNode = tilesetNode.next_sibling(
            "tileset")) {
        int firstGid = tilesetNode.attribute("firstgid").as_int();
        std::string source = tilesetNode.attribute("source").as_string();

        // Load and parse the external TSX file here, if necessary
    }

    for (pugi::xml_node layerNode = mapNode.child("layer"); layerNode; layerNode = layerNode.next_sibling("layer")) {
        std::string layerName = layerNode.attribute("name").as_string();

        pugi::xml_node dataNode = layerNode.child("data");
        std::string csvData = dataNode.child_value();

        // Split the CSV data into individual tile GIDs
        std::vector<int> tiles;
        std::stringstream ss(csvData);
        std::string value;
        while (std::getline(ss, value, ',')) {
            tiles.push_back(std::stoi(value));
        }

        // Process the tiles for this layer
    }

    for (pugi::xml_node layerNode = mapNode.child("layer"); layerNode; layerNode = layerNode.next_sibling("layer")) {
        layer.name = layerNode.attribute("name").as_string();
        layer.width = layerNode.attribute("width").as_int();
        layer.height = layerNode.attribute("height").as_int();

        std::vector<int> tiles;
        std::string csvData = layerNode.child("data").child_value();
        std::stringstream ss(csvData);
        std::string value;

        while (std::getline(ss, value, ',')) {
            tiles.push_back(std::stoi(value));
        }

        layer.tiles = tiles;
        layers.push_back(layer);
    }


    sf::Sprite sprite;
    sprite.setTexture(Images::getImage(Images::GameBackGround));
    int tilesAcross = sprite.getGlobalBounds().width / tileWidth;

    for (int id = 1; id <= 855; ++id) {
        int tu = (id - 1) % tilesAcross;
        int tv = (id - 1) / tilesAcross;
        sprite.setTextureRect(sf::IntRect(tu * tileWidth, tv * tileHeight, tileWidth, tileHeight));
        tileSprites[id] = sprite;

    }
}



void ParsingXML::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto &layer: layers) { // layers is a vector of your layer data
        for (int y = 0; y < mapHeight; ++y) {
            for (int x = 0; x < mapWidth; ++x) {
                int tileID = layer.tiles[x + y * mapWidth]; // Get the tile ID for the current position

                auto tileIt = tileSprites.find(tileID);
                if (tileIt != tileSprites.end()) {
                    sf::Sprite tile = tileIt->second; // Create a copy of the sprite
                    tile.setPosition(x * tileWidth, y * tileHeight);
                    window.draw(tile);
                }
            }
        }
    }
}

Snapshot ParsingXML::getSnapshot() const {
    return Snapshot();
}

void ParsingXML::applySnapshot(const Snapshot &snapshot) {

}

bool ParsingXML::isActive(ScreenType screen) const {
    return false;
}

void ParsingXML::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void ParsingXML::update() {

}

ParsingXML::ParsingXML() {
    Parse();
}
