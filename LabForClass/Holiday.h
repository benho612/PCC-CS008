//
// Created by hoben on 2/8/2023.
//

#ifndef LABFORCLASS_HOLIDAY_H
#define LABFORCLASS_HOLIDAY_H
#include "Date.h"

class Holiday : public Date
{
private:
    std::string name;
    std::vector<std::string> colors;
public:
    Holiday();
    Holiday(std::string name, std::vector<std::string> colors);
    Holiday(const Date& date ,std::string name, std::vector<std::string> colors);
    std::string getName();
    void setName(const std::string &name);
    std::string getColor(int index);
    void setColor(const std::string &color, int index);
    void addColors(const std::string &color);
    std::vector<std::string> getColors();
    void setColors(const std::vector<std::string> &colors);
};


#endif //LABFORCLASS_HOLIDAY_H
