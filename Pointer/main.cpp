#include "vector.h"
int main() {
    vector <int> test1(10, 0);
    vector <int>test2(test1);
    vector <int>test3;
    test3 = test1;

    test1.push_back(10);
        std::cout<< test1 << " ";

    std::cout<<"\ntest1 first element:" <<test1.front() <<std::endl;
    std::cout<<"test1 last element:" <<test1.back() <<std::endl;
    std::cout<<"test1 size: " << test1.size() <<std::endl;
    std::cout<<"test1 capacity: " << test1.capacity() <<std::endl;
    test1.pop_back();
    std::cout<<"test1 pop_backed "<<std::endl;
    std::cout<<"Value of test1 right now" << std::endl;
    for (int i=0; i<test1.size(); ++i)
    {
        std::cout<< test1.at(i) << " ";
    }

    std::cout<<"\ntest2 first element:" <<test2.front() <<std::endl;
    std::cout<< test2 << " ";
    test2.push_back(10);
    std::cout<<"\ntest2 last element:" <<test2.back() <<std::endl;

    std::cout<<"\ntest3 first element:" <<test3.front() <<std::endl;
    std::cout<< test3 << " ";
    test3.push_back(5);
    std::cout<<"\ntest3 last element:" <<test3.back() <<std::endl;







}
