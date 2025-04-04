#include <iostream>
#include "LinkedList.h"
int main() {
    LinkedList<int> test1;
    LinkedList<int> test3;
    test1.pushFront(1);
    test1.pushBack(2);
    test1.insertBefore(5,2);
    std::cout<<"\n" << test1;
    test1.insertBefore(25,2);
    std::cout<<"\n" << test1;
    test1.insertAfter(10,5);
    test3 = test1;
    LinkedList<int> test2(test1);
    std::cout<<"\ntest1: " << test1;
    std::cout<<"\ntest2: " << test2;
    std::cout<<"\ntest3: " << test3;




    test1.remove(10);
    std::cout<<"\n" << test1;
    std::cout <<"\ntest1 size is " <<test1.size() << std::endl;


    std::cout<<"\n" << test1;
    test1.popFront();


    std::cout<<"\n" << test1;
    test1.popBack();


    std::cout<<"\n" << test1;
    std::cout<<"\ntest1 first value is " << test1.front();
    std::cout<<"\ntest1 last value is " << test1.back();


    if(test1.empty())
        std::cout <<"\nIt is empty";
    else
        std::cout<<"\nIt is not empty";
}
