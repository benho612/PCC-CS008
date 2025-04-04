//
// Created by hoben on 1/26/2023.
//

#include "function.h"

std::vector<std::string> split(std::string target, std::string delimiter) {
    std::vector<std::string> v;
    while ((target.find(delimiter)) != std::string::npos)
    {
        int pos = target.find(delimiter);
        std::string sub = target.substr(0,pos);
        v.push_back(sub);
        target.erase(0,pos+delimiter.length());
    }
    v.push_back(target);
    for (const auto & i : v)
    {
        std::cout << i<< " ";
    }
}