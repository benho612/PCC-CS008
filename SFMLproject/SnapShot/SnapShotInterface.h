//
// Created by hoben on 11/1/2023.
//

#ifndef TYPING_SNAPSHOTINTERFACE_H
#define TYPING_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapShotInterface {
public:
// this function will return a snapshot of the object's current state
    virtual Snapshot getSnapshot() const = 0;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};

#endif //TYPING_SNAPSHOTINTERFACE_H
