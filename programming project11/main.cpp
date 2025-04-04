#include <iostream>
#include "Movie.h"
using namespace std;
int main() {
    Movie test1("Sword Art Online Progressive","PG-13");
    test1.addRating(5);
    test1.addRating(5);
    test1.addRating(5);
    test1.addRating(5);
    test1.addRating(5);

    cout<<"Movie Name: "<<test1.getName()<<endl;
    cout<<"mpaa Rating: "<<test1.getMpaaRating()<<endl;
    cout<<"Average Rating: "<<test1.getAverage()<<endl<<endl;

    Movie test2("Black Panther: Wakanda Forever","PG-13");
    test2.addRating(4);
    test2.addRating(3);
    test2.addRating(4);
    test2.addRating(4);
    test2.addRating(3);

    cout<<"Movie Name: "<<test2.getName()<<endl;
    cout<<"mpaa Rating: "<<test2.getMpaaRating()<<endl;
    cout<<"Average Rating: "<<test2.getAverage()<<endl;

    return 0;

}
