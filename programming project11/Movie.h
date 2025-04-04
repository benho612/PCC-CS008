//
// Created by Ben Ho on 2/6/2023.
//

#ifndef PROGRAMMING_PROJECT10_MOVIE_H
#define PROGRAMMING_PROJECT10_MOVIE_H
#include <iostream>
#include <string>

class Movie {
private:
    std::string name;
    std::string mpaaRating;
    int one,two,three,four,five;
public:
    std::string getName();
    std::string getMpaaRating();
    double getAverage();
    void addRating(int rating);
    Movie();
    Movie(std::string name, std::string mpaaRating);
};


#endif //PROGRAMMING_PROJECT10_MOVIE_H
