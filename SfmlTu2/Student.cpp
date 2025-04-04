//
// Created by hoben on 4/5/2023.
//

#include "Student.h"

int Student::getStudentId() const {
    return studentID;
}

void Student::setStudentId(int studentId) {
    studentID = studentId;
}

void Student::print() {
    Person::print();
    std::cout <<", " <<studentID << std::endl;
}

Student::Student(const std::string &first, const std::string &last) : Person(first, last) {

}

Student::Student():Person() {

}

void Student::getFavoriteFood() {
    std::cout << "Etidde";
}
