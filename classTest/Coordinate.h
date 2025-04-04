//
// Created by hoben on 2/2/2023.
//

#ifndef CLASSTEST_COORDINATE_H
#define CLASSTEST_COORDINATE_H

template<typename T>
class Coordinate {
private:
    T x, y;
public:
    //getters and setters
    T getX();
    T getY();
    void setX(T x);
    void setY(T y);

    //constructor
    Coordinate();
    Coordinate(T x,T y);
};




#endif //CLASSTEST_COORDINATE_H
