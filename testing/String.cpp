//
// Created by hoben on 9/20/2023.
//

#include "String.h"

std::vector<String> String::split(std::string& S) {
    std::vector<String> storage;
    int start = 0;
    int pos = 0;
    do {
        pos = S.find(' ');
        String temp = S.substr(start, pos);
        storage.emplace_back(temp);
        S.erase(start, pos + 1);
    } while (pos != -1);

    return storage;
}
std::vector<String> String::split(std::string &S, char delimited) {
    std::vector<String> storage;
    int start = 0;
    int pos = 0;
    do {
        pos = S.find(delimited);
        String temp = S.substr(start, pos);
        storage.emplace_back(temp);
        S.erase(start, pos + 1);
    } while (pos != -1);

    return storage;
}


String::String():std::string(){}

String::String(const char *s): std::string(s) {

}

String::String(const std::string& s):std::string(s) {

}



