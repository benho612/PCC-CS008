//
// Created by hoben on 2/7/2023.
//

#ifndef CLASSLAB_DATE_H
#define CLASSLAB_DATE_H
#include <string>
#include <vector>
class Date {
private:
    int month, day, year = 0;
    std::string fullDate;
    std::vector <std::string> months = {"January", "February", "March", "April", "May", "June","July","August",
                                        "September", "October", "November", "December"};
public:
    std::string getDate(std::string format);
    std::string getDate();
    int getDay();
    void setDay(int day);
    int getmonth();
    void setMonth(int month);
    int getYear();
    void setYear(int year);
    Date();
    Date(int month,int day,int year);
    void changes(std::string&format);
    bool checkConsuctive(std::string&format);
    friend bool operator == (const Date &dateLeft, const Date & dateRight);
    friend Date operator +(Date& date, int number);
    friend Date operator -(Date& date, int number);
    void operator = (const Date &date);
    friend std::ostream& operator <<(std::ostream &out, Date& date);

};




#endif //CLASSLAB_DATE_H
