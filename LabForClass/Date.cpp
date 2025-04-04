//
// Created by hoben on 2/7/2023.
//

#include <iomanip>
#include <iostream>
#include "Date.h"

Date::Date() : month(2), day(7), year(2023) {
}

Date::Date(int month, int day, int year) : month(month), day(day), year(year) {
}

int Date::getDay() {
    return day;
}

int Date::getmonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

std::string Date::getDate(std::string format) {
    changes(format);
    return format;
}

void Date::changes(std::string &format) {
    int x = 0;
    while (x < 3)
    {
        std::string temp;
        if (format.find("MM") != std::string::npos)
        {
            format.replace(format.find('M'), 2 , months[month-1]);
        }
        else if (format.find('M')!= std::string::npos)
        {
            std::string substr = months[month-1];
            format.replace(format.find('M'),1 , substr.substr(0, 3));
        }
        else if (format.find('m')!= std::string::npos && checkConsuctive(format))
        {
            if (month <= 9)
            {
                temp = std::to_string(month);
                temp.insert(0, "0");
                format.replace(format.find('m'),1 , temp);
            }
            else
            {
                temp = std::to_string(month);
                format.replace(format.find('m'),1 , temp);
            }
        }
        else if (format.find('d')!= std::string::npos)
        {
            if (day <= 9)
            {
                temp = std::to_string(day);
                temp.insert(0, "0");
                format.replace(format.find('d'),1 , temp);
            }
            else
            {
                format.replace(format.find('d'),1 , std::to_string(day));
            }
        }
        else if (format.find("YY")!= std::string::npos)
        {
            format.replace(format.find('Y'), 2 , std::to_string(year));

        }
        else if (format.find('Y') != std::string::npos)
            {
                year = year % 100;
                temp = std::to_string(year);
                format.replace(format.find('Y'), 1, temp);
            }
            x++;
    }
}

bool Date::checkConsuctive(std::string &format) {
    if(format.find(months[month-1]) != std::string::npos )
        return false;
    else
        return true;
}

bool operator == (const Date &dateLeft, const Date &dateRight) {
    return dateLeft.month == dateRight.month && dateLeft.day == dateRight.day
    && dateLeft.year  == dateRight.year;
}

Date operator-(Date &date, int number) {
    return{date.month, date.day, date.year - number};
}

Date operator+(Date &date, int number) {
    return {date.month, date.day, date.year + number};
}

void Date::operator = (const Date &date) {
    month = date.month;
    day = date.day;
    year = date.year;
}

std::ostream &operator<<(std::ostream &out, Date &date) {
    out << date.month<<"/"<<date.day<<"/"<<date.year<<"\n";
    return out;
}

std::string Date::getDate() {
    std::string temp = std::to_string(getmonth()) + "/" + std::to_string(getDay())
            + "/" + std::to_string(getYear());
    return temp;
}














