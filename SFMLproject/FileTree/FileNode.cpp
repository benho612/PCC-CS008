//
// Created by Ben Ho on 11/19/2023.
//

#include "FileNode.h"

void FileNode::toggleChildren() {
    this->_showChildren = !this->_showChildren;


}

FileNode::FileNode() = default;

FileNode::FileNode(Images::Image icon, const std::string& text, sf::Vector2f size, sf::Vector2f position)
: data(icon, text, size, position){
    this->_showChildren = false;
}

FileNode::FileNode(FileNode *_parentNode, Images::Image icon, const std::string &text, sf::Vector2f size, sf::Vector2f position)
                   :data(icon, text, size, position),parentNode(_parentNode)
{
    this->_showChildren = false;
    if (_parentNode == nullptr) {
        parentNode = nullptr; // Explicitly set to nullptr for the root node
    }

}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    // Draw this node's FileItem
    data.draw(window, states);
    if (!_showChildren) return;

    // Draw children if they are visible
    for (auto& child : children)
    {
        child->draw(window, states);
    }
}


void FileNode::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::mouseClicked(data.getBox(),window))
    {
        toggleChildren(); // Toggle visibility of children
        reposition();
        if (!_showChildren && parentNode)
            parentNode->repositionSiblingsFrom(this);
    }

    data.eventHandler(window,event);

    for (auto& child : children) {
        if (!this->_showChildren)
        {
            child->showChildren(false);
        }
        child->getData().eventHandler(window,event);
    }

}

void FileNode::update() {
    for (auto& child : children) {
        child->getData().update();
    }

    data.update();
}

void FileNode::applySnapshot(const Snapshot &snapshot) {

}

Snapshot FileNode::getSnapshot() const {
    return Snapshot();
}

sf::FloatRect FileNode::getGlobalBounds() {
    return data.getGlobalBounds();
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode *> & FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}

void FileNode::showChildren(bool showChildren) {
    {
        this->_showChildren = showChildren;
    }
}

bool FileNode::childrenShown() const {
    return this->_showChildren;
}

void FileNode::setPosition(const sf::Vector2f &position) {
    data.setPosition(position); // Set the position of the FileItem
    reposition();
}


void FileNode::reposition() {

    if (isLeaf() || !_showChildren) return;


    float currentY = this->data.getPosition().y + this->data.getSize().y + 5;

    if (_showChildren) {
        for (auto &child: children) {
            float indentX = this->data.getPosition().x + horizontalIndent;
            child->setPosition({indentX, currentY});
            currentY += child->getData().getGlobalBounds().height;
        }
    }

    if (parentNode) {
        float newY = getBottomY() + verticalSpacing;
        bool startShifting = false;
        for (auto& sibling : parentNode->children) {
            if (startShifting) {
                sibling->setPosition({sibling->getPosition().x, newY});
                newY = sibling->getBottomY() + verticalSpacing;
            }
            if (sibling == this) {
                startShifting = true;
            }
        }
    }

    if (parentNode && parentNode->parentNode) {
        parentNode->repositionSiblingsFrom(this);
    }

}



sf::Vector2f FileNode::getPosition() {
    return data.getPosition();
}


sf::Vector2f FileNode::getSize() {
    return data.getSize();
}

void FileNode::repositionSiblingsFrom(FileNode *startingNode) {
    if (parentNode == nullptr)
        return;

    float nextY = startingNode->getBottomY() + verticalSpacing;
    bool foundStartingNode = false;

    for (auto& sibling : parentNode->children) {
        if (foundStartingNode) {
            // Reposition the sibling to the new Y position.
            sibling->setPosition({sibling->getPosition().x, nextY});
            nextY = sibling->getBottomY() + verticalSpacing;
        }

        if (sibling == startingNode) {
            foundStartingNode = true;
        }
    }

    // If this node also has a parent, continue the process upwards
    if (parentNode->parentNode != nullptr) {
        parentNode->repositionSiblingsFrom(parentNode);
    }
}

float FileNode::getBottomY() const {
    float bottomY = this->data.getPosition().y + this->data.getGlobalBounds().height;

    // If this node has children and they are shown
    if (_showChildren && !children.empty()) {
        bottomY = this->children.back()->getBottomY();
    }

    return bottomY;
}

FileNode *FileNode::getParentNode() const {
    return parentNode;
}

void FileNode::setParentNode(FileNode *_parentNode) {
    this->parentNode = _parentNode;
}

bool FileNode::isActive(ScreenType screen) const {
    return false;
}







