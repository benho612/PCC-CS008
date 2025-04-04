//
// Created by hoben on 2/23/2023.
//

#ifndef POINTER_VECTOR_H
#define POINTER_VECTOR_H
#include <iostream>

template <typename T>
class vector;

template<typename T>
std::ostream& operator <<(std::ostream& out, const vector<T>& a);


template <typename T>
class vector {
private:
    int _capacity = 0;
    int _size = 0;
    T *arr = nullptr;
    void resize(); //if array full double the array.
public:
    vector();
    vector(int size, const T& defaultValue);
    vector(int size);
    vector(vector<T>&obj);
    ~vector();
    void push_back(const T& number);
    int size() const;
    int capacity();
    bool empty();
    T& front();
    T& back();
    void pop_back();
    T& at(int index);
    vector& operator =(const vector<T> &oldObj);
    int operator[](unsigned int index) const;
    friend std::ostream& operator << <T>(std::ostream& out, const vector<T>& a);
};



#include "vector.cpp"

#endif //POINTER_VECTOR_H
