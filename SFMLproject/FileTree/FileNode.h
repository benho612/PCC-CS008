//
// Created by Ben Ho on 11/19/2023.
//

#ifndef SFMLPROJECT_FILENODE_H
#define SFMLPROJECT_FILENODE_H


#include "../Interface/GUIComponent.h"
#include "FileItem.h"
#include "../Helper/MouseEvents.h"
#include "../Helper/Image.h"
class FileNode : public GUIComponent, public States
{
private:
    //This is the data represented in the tree
    FileItem data;
    bool _showChildren;
    FileNode* parentNode;
    std::vector<FileNode*> children;
    void toggleChildren();
    const float horizontalIndent = 20.0f;
    const float verticalSpacing = 5.0f;

public:
    typedef typename std::vector<FileNode*>::iterator iterator;
    ///constructor
    FileNode();

    ///constuctor
    FileNode(Images::Image icon, const std::string& text, sf::Vector2f size, sf::Vector2f position);

    FileNode(FileNode* _parentNode, Images::Image icon, const std::string& text, sf::Vector2f size, sf::Vector2f position);

    ///GUIComponent
    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot getSnapshot() const override;
    void applySnapshot(const Snapshot& snapshot) override;
    bool isActive(ScreenType screen) const; // Add this method

    ///get&set object
    sf::FloatRect getGlobalBounds();
    bool isLeaf() const;
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode *> & getChildren();

    iterator begin();
    iterator end();


    void showChildren(bool showChildren);
    bool childrenShown() const;

    //this is called in the draw function to reposition the children so they
    // are indented and below the parent
    void reposition();
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    float getBottomY() const;
    FileNode *getParentNode() const;

    void setParentNode(FileNode *_parentNode);
    void repositionSiblingsFrom(FileNode* startingNode);
};

#endif //SFMLPROJECT_FILENODE_H
