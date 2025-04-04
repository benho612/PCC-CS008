#include <iostream>
//#include "Stack.h"
//#include "Queue.h"
#include "DoublyLinkedList.h"
#include <algorithm>
int main() {
    DoublyLinkedList<int> test;
    test.push_front(5);
    test.push_front(20);
    test.push_front(15);
    test.push_back(0);
    test.insertAfter(12,5);
    std::cout << test << std::endl;


    //std::cout <<"before looping\n";
    //std::reverse(test.begin(),test.end());

   /* std::cout <<"After looping\n";
    do
    {
        std::cout << test << std::endl;
    }while(std::prev_permutation(test.begin(),test.end()));


    auto pend = std::remove (test.begin(), test.end(), 20);
    std::cout << "range contains:";
    for (auto p= test.begin(); p!= pend; ++p)
        std::cout << ' ' << *p;
    std::cout << '\n';

    std::cout << test << std::endl;


    /*Stack<std::string> test;
    test.push("First");
    test.push("Second");
    test.push("Third");
    test.print();
    std::cout << "_________" << std::endl;
    test.pop();
    test.print();*/

    /*Queue<std::string> test;
    test.push("First");
    test.push("Second");
    test.push("Third");
    test.print();
    std::cout << "---------" << std::endl;
    test.print();*/

}
