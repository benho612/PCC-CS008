
#include "VectorDouble.h"
int main() {
    VectorDouble test1(12);
    VectorDouble test2;
    for(int i= 0; i< 10;++i)
    {
        test1.push_back(i);
    }
    std::cout<<"test1 size: "<<test1.size() <<std::endl;
    std::cout<<"test1 capacity: "<<test1.capacity()<<std::endl;
    test2.reserve(25);
    test2.resize(10);
    std::cout<<"test2 size: "<<test2.size() <<std::endl;
    std::cout<<"test2 capacity: "<<test2.capacity()<<std::endl;
    VectorDouble test3(test1);
    std::cout<<"test3 size: "<<test3.size() <<std::endl;
    std::cout<<"test3 capacity: "<<test3.capacity()<<std::endl;
    if (test1 == test2)
        std::cout<<"same"<<std::endl;
    else
        std::cout<<"not same"<<std::endl;
    std::cout<<"test1 value at 5 is " <<test1.value_at(5)<<std::endl;
    test1.change_value_at(10, 5);
    std::cout<<"change test1 value at 5 : " <<test1.value_at(5)<<std::endl;


}
