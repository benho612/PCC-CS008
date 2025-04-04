//
// Created by hoben on 2/28/2023.
//

#ifndef DYNAMIC_2D_ARRAY_TWODARRAY_H
#define DYNAMIC_2D_ARRAY_TWODARRAY_H
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

class twoDArray : public sf::Drawable{
public:
    twoDArray();
    twoDArray(int rows, int colos);
    twoDArray(const twoDArray& d);
    ~twoDArray() override;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event &event);
    twoDArray& operator=(const twoDArray& a);


private:
    sf::RectangleShape ** ptr = nullptr;
    int rows, colos;
    sf::RectangleShape newRectangleShape(float x, float y);
    void createArray();
    void fillArray();
    void decreaseArray();
    void increaseArray();



};


#endif //DYNAMIC_2D_ARRAY_TWODARRAY_H
