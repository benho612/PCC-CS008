//
// Created by hoben on 4/10/2023.
//

#ifndef SFMLTU_IMAGES_H
#define SFMLTU_IMAGES_H
#include <map>
#include "SFML/Graphics.hpp"
enum images{PHASER, PLAYINGSPRITE};

class Images {
private:
    static std::map<images, sf::Texture> textures;
    static std::string getPath(images image);
    static void load(images image);
public:
    static sf::Texture& getImage(images image);
};


#endif //SFMLTU_IMAGES_H
