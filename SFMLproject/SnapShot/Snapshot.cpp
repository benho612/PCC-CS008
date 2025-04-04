//
// Created by hoben on 11/1/2023.
//

#include "Snapshot.h"


Snapshot::Snapshot() = default;

Snapshot::Snapshot(const std::string& object)
{
    this->state = object;
}

const std::string &Snapshot::getState() const {
    return this->state;
}



