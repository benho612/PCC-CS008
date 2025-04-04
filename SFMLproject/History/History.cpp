//
// Created by hoben on 11/7/2023.
//

#include <iostream>
#include "History.h"

std::stack<HistoryNode>History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    if (!stack.empty())
        stack.pop();
    else
        return ;
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(KeyboardShortcut::isUndo())
    {
        undo();
    }
}

bool History::isEmpty() {
    if(stack.empty())
        return true;
    else
        return false;
}

void History::undo() {
    if(stack.empty()) return ;
    HistoryNode &node = stack.top();
    node.component->applySnapshot(node.snapshot);
    popHistory();
}
