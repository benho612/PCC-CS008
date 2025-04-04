//
// Created by hoben on 2/28/2023.
//

#include "twoDArray.h"

twoDArray::twoDArray():rows(1), colos(1) {
    createArray();
    fillArray();
}

twoDArray::twoDArray(int rows, int col):rows(rows),colos(col) {
    createArray();
    fillArray();
}

twoDArray::twoDArray(const twoDArray &d) {
    this->operator=(d);
}

twoDArray::~twoDArray() {
    for(int i=0;i<rows;++i)
    {
        delete [] *(ptr+i);
    }
    delete [] ptr;
}

void twoDArray::createArray() {
    ptr = new sf::RectangleShape* [rows];
    for (int i = 0; i < rows; ++i) {
        *(ptr + i) = new sf::RectangleShape[colos];
    }
}

void twoDArray::fillArray() {
    float y = 0;
    float x = 0;
    for(int i =0; i<rows; ++i)
    {
        for(int j=0; j<colos;++j)
        {
            *(*(ptr+i)+j)= newRectangleShape(x,y);
            x+= 20;
        }
        x = 0;
        y += 20;
    }
}

sf::RectangleShape twoDArray::newRectangleShape(float x, float y) {
    sf::RectangleShape rectangle;
    rectangle.setSize({20,20});
    rectangle.setPosition({x,y});
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;
    rectangle.setFillColor(sf::Color(r,g,b));
    return rectangle;
}

void twoDArray::decreaseArray() {
    //this->~twoDArray();
    for(int i=0; i< rows; ++i)
    {
        delete [] *(ptr+i);
    }
    delete [] ptr;

    rows -= 1;
    colos -= 1;
    createArray();
    fillArray();
}

void twoDArray::increaseArray() {
    //this->~twoDArray();
    for(int i=0; i< rows; ++i)
    {
        delete [] *(ptr +i);
    }
    delete [] ptr;
    rows += 1;
    colos += 1;
    std::cout<<"rows " << rows <<std::endl;
    createArray();
    std::cout<<"colos " << colos << std::endl;
    fillArray();
}



void twoDArray::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i =0; i<rows;++i)
    {
        for (int j = 0; j < colos; ++j) {
            window.draw(*(*(ptr+i)+j));
        }
    }
}

void twoDArray::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            decreaseArray();
            std::cout<<"Left" <<std::endl;
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
        }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            increaseArray();
            std::cout<<"Right" <<std::endl;
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
        }


    }

twoDArray& twoDArray::operator=(const twoDArray &a) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colos; ++j) {
            *(ptr+i) = *(a.ptr + i);
        }
    }
}





