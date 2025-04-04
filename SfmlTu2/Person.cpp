//
// Created by hoben on 4/5/2023.
//

#include "Person.h"

Person::Person() = default;

Person::Person(const std::string &first, const std::string &last):firstName(first), lastName(last) {
}

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

std::ostream &operator<<(std::ostream &out, const Person &person) {
    return out << person.firstName << " " << person.lastName;
}

void Person::print() {
    std::cout<< *this;
}
