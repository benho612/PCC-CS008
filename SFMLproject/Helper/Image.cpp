//
// Created by Ben Ho on 11/19/2023.
//

#include "Image.h"

std::unordered_map<Images::Image, sf::Texture> Images::texture;

sf::Texture &Images::getImage(Image image) {
    Images::LoadFromFile(image);
    return texture[image];
}

void Images::LoadFromFile(Image image) {
    texture[image].loadFromFile(getFilePath(image));

}

std::string Images::getFilePath(Image image) {
    std::string path = "FileTree/FileIcon/";

    switch (image) {
        case file:
            return path + "file.png";
        case folder:
            return path + "folder.png";
        case All:
            return "Player/Images/Sprites.png";
        case walking:
            return "Player/Images/SpriteSheet.png";
        case MainMenuBackGround:
            return "MainMenu/MainMenuBackGround.jpg";
        case GameBackGround:
            return "Testing/Serene_Village_32x32.png";
        case PausingBackGround:
            return "PausingScreen/PausingMenu.png";
        default:
            return path + "file.png";
    }
}
