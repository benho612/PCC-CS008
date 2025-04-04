//
// Created by hoben on 4/5/2023.
//

#ifndef SFMLTU2_PERSON_H
#define SFMLTU2_PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string firstName, lastName;
public:
    Person();
    Person(const std::string& first, const std::string& last);
    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    friend std::ostream& operator <<(std::ostream& out, const Person& person);

    virtual void print();

    virtual void getFavoriteFood() = 0;
};


#endif //SFMLTU2_PERSON_H
