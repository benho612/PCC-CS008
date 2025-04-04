//
// Created by hoben on 11/1/2023.
//

#ifndef TYPING_SNAPSHOT_H
#define TYPING_SNAPSHOT_H
#include <SFML/Graphics.hpp>
#include "../States/States.h"
#include "../TextInputBox/Letter.h"

class Snapshot {
private:
    std::string state;
public:
    Snapshot();


    explicit Snapshot(const std::string &object);

    const std::string& getState()const;
};

#endif //TYPING_SNAPSHOT_H
