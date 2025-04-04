//
// Created by hoben on 11/7/2023.
//

#ifndef TYPING_HISTORYNODE_H
#define TYPING_HISTORYNODE_H
#include "../SnapShot/Snapshot.h"
#include "../Interface/GUIComponent.h"

struct HistoryNode
{
public:
    Snapshot snapshot;
    GUIComponent* component;
    HistoryNode() = default;
    HistoryNode(const Snapshot& snapshot, GUIComponent& component):snapshot(snapshot),
    component(&component){};
};


#endif //TYPING_HISTORYNODE_H
