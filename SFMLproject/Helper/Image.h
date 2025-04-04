//
// Created by Ben Ho on 11/19/2023.
//

#ifndef SFMLPROJECT_IMAGE_H
#define SFMLPROJECT_IMAGE_H

#include <unordered_map>
#include <SFML/Graphics.hpp>


class Images{
public:
    enum Image {file, folder, All, walking, MainMenuBackGround, GameBackGround, PausingBackGround, last_Image };
    static sf::Texture& getImage(Image image);
private:
    static void LoadFromFile(Image image);
    static std::string getFilePath(Image image);
    static std::unordered_map<Image, sf::Texture> texture;
};


#endif //SFMLPROJECT_IMAGE_H
