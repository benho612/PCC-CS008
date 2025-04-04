//
// Created by hoben on 4/5/2023.
//

#ifndef SFMLTU2_STUDENT_H
#define SFMLTU2_STUDENT_H
#include "Person.h"

class Student:public Person {
private:
    int studentID;
public:
    Student();
    Student(const std::string& first, const std::string& last);
    int getStudentId() const;
    void setStudentId(int studentId);
    void print();
    virtual void getFavoriteFood();

};


#endif //SFMLTU2_STUDENT_H
