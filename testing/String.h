//
// Created by hoben on 9/20/2023.
//

#ifndef TESTING_STRING_H
#define TESTING_STRING_H

#include <iostream>
#include <string>
#include <vector>
class String :public std::string {
public:
    String();
    String(const char*s);
    String(const std::string& s);
    std::vector<String> split(std::string& S);
    std::vector<String> split(std::string& S, char delimited = ' ');
private:


};


#endif //TESTING_STRING_H
