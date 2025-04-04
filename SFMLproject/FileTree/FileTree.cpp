//
// Created by Ben Ho on 11/19/2023.
//

#include "FileTree.h"

void FileTree::push(FileNode *&node, const std::string& parent, const std::string& item) {
    if (node == nullptr) {
        node = new FileNode(nullptr,Images::folder, parent, sf::Vector2f(150, 30), initPosition);
        // If parent is empty, this is the first node
        if (!parent.empty()) {
            auto pushBackNode = new FileNode(nullptr,Images::folder, item, sf::Vector2f(150, 30), initPosition);
            node->getChildren().push_back(pushBackNode);
        }
        return;
    }

    if (node->getData().getText() == parent) {
        // If the parent is found, add the new item as a child
        auto pushBackNode = new FileNode(node,Images::file, item, sf::Vector2f(150, 30), initPosition);
        node->getChildren().push_back(pushBackNode);
        pushBackNode->setParentNode(node); // set the parent node for the new child

    } else {
        // Otherwise, look for the parent in the children
        for (auto& child : node->getChildren()) {
            push(child, parent, item);
            child->setParentNode(node); // ensure the parent node is set for each child
        }
    }
}


void FileTree::traverse(FileNode *&_root, sf::RenderWindow &window, sf::Event event) {
    if (_root != nullptr) {
        _root->eventHandler(window, event);
        for (auto& child : _root->getChildren()) {
            traverse(child, window, event);
        }
    }
}

FileTree::FileTree() = default;

FileTree::~FileTree() {
    delete root;
}

void FileTree::push(const std::string& parent, const std::string& item) {
    push(root, parent, item);
    if (root != nullptr) {
        root->reposition();
    }
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (root != nullptr) {
        root->draw(window, states);
    }
}

void FileTree::applySnapshot(const Snapshot &snapshot) {

}

Snapshot FileTree::getSnapshot() const {
}

sf::FloatRect FileTree::getGlobalBounds() {
}
void FileTree::eventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root, window, event);

}

void FileTree::update() {
    if (root != nullptr) {
        root->update();
    }
}

void FileTree::printTree(FileNode *node, int level) {
    if (node == nullptr) {
        return;
    }

    // Print spaces for indentation based on the level of this node
    for (int i = 0; i < level; ++i) {
        std::cout << "  "; // Two spaces for each level
    }

    std::cout << node->getData().getText() << std::endl;

    // Recursively print each child, increasing the indentation level
    for (const auto& child : node->getChildren()) {
        printTree(child, level + 1);
    }
}

FileNode *FileTree::getRoot() const {
    return root;
}

bool FileTree::isActive(ScreenType screen) const {
    return false;
}


