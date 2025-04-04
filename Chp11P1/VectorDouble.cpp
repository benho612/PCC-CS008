//
// Created by Ben Ho on 2/19/2023.
//

#include "VectorDouble.h"

VectorDouble::VectorDouble():max_count(50) {
    array = new double[max_count];
    count = 0;

}
VectorDouble::VectorDouble(int number):max_count(number){
    array = new double[max_count];
    count = 0;
}
VectorDouble::VectorDouble(VectorDouble &oldObj) {
    max_count = oldObj.max_count;
    auto * temp = new double[max_count];
    for (int i = 0; i < oldObj.size(); ++i) {
        temp[i]= oldObj.value_at(i);
        count++;
    }
    array = temp;
}
VectorDouble::~VectorDouble() {
    max_count = 0;
    delete [] array;
}


void VectorDouble::operator= ( VectorDouble &oldObj) {
    auto * temp = new double[oldObj.count];
    for (int i = 0; i < oldObj.size(); ++i) {
        temp[i] = oldObj.value_at(i);
    }
    count = oldObj.size();
    array = temp;
}

bool operator==(const VectorDouble &A1, const VectorDouble &A2) {
    if(A1.count == A2.count)
        return true;
    return false;
}

void VectorDouble::push_back(int number) {
    if(count < max_count)
    {
        array[count] = number;
        count++;
    }
    else
    {
        std::cout<<"Error"<<std::endl;
        exit(1);
    }
}

int VectorDouble::size() const {
    return count;
}

int VectorDouble::capacity() const {
    return max_count;
}

void VectorDouble::reserve(int number) {
    max_count = number;
    auto * temp = new double[max_count];
    for (int i = 0; i < count; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void VectorDouble::resize(int number) {
    count = number;
    auto * temp = new double[count];
    for (int i = 0; i < count; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

double VectorDouble::value_at(int index) {
    if(index < 0 || index > count)
    {
        std::cout<<"Out of Bound"<<std::endl;
        exit(1);
    }
    else
    {
        return array[index];
    }
}

void VectorDouble::change_value_at(double number, int index) {
    array[index] = number;
}











