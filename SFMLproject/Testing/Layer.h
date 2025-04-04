//
// Created by Ben Ho on 12/8/2023.
//

#ifndef SFMLPROJECT_LAYER_H
#define SFMLPROJECT_LAYER_H

#include <string>
#include <vector>

struct Layer {
    std::string name;
    int width, height;
    std::vector<int> tiles;
};

#endif //SFMLPROJECT_LAYER_H
