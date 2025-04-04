//
// Created by Ben Ho on 2/6/2023.
//

#include "Movie.h"

#include <utility>

Movie::Movie() {
}

Movie::Movie(std::string name, std::string mpaaRating):name(std::move(name)), mpaaRating(std::move(mpaaRating)) {
    one = 0;
    two = 0;
    three = 0;
    four = 0;
    five = 0;
}

std::string Movie::getName() {
    return name;
}

std::string Movie::getMpaaRating() {
    return mpaaRating;
}

void Movie::addRating(int rating) {
        switch(rating){
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            case 3:
                three++;
                break;
            case 4:
                four++;
                break;
            case 5:
                five++;
                break;
            default:
                std::cout<<"wrong rating"<<std::endl;
                break;
        }
}

double Movie::getAverage() {
    double avg = (one*1.0 + two*2.0 + three*3.0 + four*4.0 +five*5.0) / (one+two+three+four+five);
    return avg;
}






