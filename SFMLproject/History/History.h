//
// Created by hoben on 11/7/2023.
//

#ifndef TYPING_HISTORY_H
#define TYPING_HISTORY_H


#include <stack>
#include "HistoryNode.h"
#include "../Helper/KeyboardShortcut.h"
class History  {
private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static bool isEmpty();
    static void undo();
};

#endif //TYPING_HISTORY_H
