#include "Person.h"
#include "Student.h"

void print(Person& p)
{
    p.print();
}

int main() {
    Student s("Royce", "Jamerson");
    s.setStudentId(42400);
    s.getFavoriteFood();
    print(s);
    return 0;
}
