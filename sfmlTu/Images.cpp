//
// Created by hoben on 4/10/2023.
//

#include "Images.h"

std::map<images, sf::Texture> Images::textures;

std::string Images::getPath(images image) {
    switch(image)
    {
        case PHASER: return "images/phaser.png";
            break;
        case PLAYINGSPRITE: return "images/playingSprite.png";
            break;
    }
    return std::string();
}

void Images::load(images image) {
    textures[image].loadFromFile(getPath(image));
}

sf::Texture& Images::getImage(images image) {
    load(image);
    return textures[image];
}
