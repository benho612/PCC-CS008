//
// Created by hoben on 2/8/2023.
//

#include "Holiday.h"

std::string Holiday::getName() {
    return name;
}

void Holiday::setName(const std::string &name) {
    this->name = name;
}

std::string Holiday::getColor(int index) {
    return colors[index];
}

void Holiday::setColor(const std::string &color, int index) {
    this->colors[index] = color;
}

Holiday::Holiday():name(0), colors(0), Date() {
}

Holiday::Holiday(std::string name, std::vector<std::string> colors):name(name), colors(colors) {
}

void Holiday::addColors(const std::string &color) {
    colors.push_back(color);
}

std::vector<std::string> Holiday::getColors() {
    return colors;
}

Holiday::Holiday(const Date &date, std::string name, std::vector<std::string> colors):Date(date),name(name),colors(colors) {
}

void Holiday::setColors(const std::vector<std::string> &colors) {
    this->colors = colors;
}




