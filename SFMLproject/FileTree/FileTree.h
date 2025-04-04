//
// Created by Ben Ho on 11/19/2023.
//

#ifndef SFMLPROJECT_FILETREE_H
#define SFMLPROJECT_FILETREE_H


#include "FileNode.h"

class FileTree : public GUIComponent
{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& node, const std::string& parent, const std::string& item);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);

    sf::Vector2f initPosition = {0, 0};


public:
    //constructors
    FileTree();

    //destructor
    ~FileTree();

    FileNode *getRoot() const;

    //this is the public version of push
    void push(const std::string& parent, const std::string& item = "NULL");

    //draws the root node of the tree
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    //calls the traverse function to add the event handlers to each node
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    void update();
    void applySnapshot(const Snapshot& snapshot);
    Snapshot getSnapshot() const;
    bool isActive(ScreenType screen) const; // Add this method


    void printTree(FileNode *node, int level = 0);


    virtual sf::FloatRect getGlobalBounds();
};

#endif //SFMLPROJECT_FILETREE_H
