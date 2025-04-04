//
// Created by hoben on 2/23/2023.
//
#ifndef POINTER_VECTOR_CPP
#define POINTER_VECTOR_CPP

#include "vector.h"

template<typename T>
vector<T>::vector() {
    _capacity = 0;
    _size = 0;
    arr = nullptr;
}

template<typename T>
vector<T>::vector(int size, const T &defaultValue):_size(size) {
    arr = new T [size];
    for(int i=0; i<size; ++i)
    {
        arr[i] = defaultValue;
    }
    _capacity = _size;
}

template<typename T>
vector<T>::vector(int size):_size(size) {
    arr = new T[size];
    _capacity = size;
}

template<typename T>
vector<T>::vector(vector<T> &obj):vector<T>() {
    operator=(obj);
}

template<typename T>
vector<T>::~vector() {
    delete [] arr;
}

template<typename T>
void vector<T>::push_back(const T &number) {
    if(_capacity == _size)
    {
        resize();
        arr[_size] = number;
        _size++;
    }
    else
    {
        arr[_size] = number;
        _size++;
    }

}

template<typename T>
int vector<T>::size() const{
    return _size;
}
template<typename T>

int vector<T>::capacity() {
    return _capacity;
}

template<typename T>
bool vector<T>::empty() {
    if(_size == 0)
        return true;
    return false;
}


template<typename T>
T &vector<T>::front() {
    return arr[0];
}


template<typename T>
T &vector<T>::back() {
    return arr[size()-1];
}


template<typename T>
T &vector<T>::at(int index) {
    if(index < 0 || index > _size)
    {
        std::cout<<"Out of Bound";
        exit(1);
    }
    else
    {
        return arr[index];
    }
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T> &oldObj) {
    if (&oldObj != this)
    {
        _capacity = oldObj._capacity;
        T * temp = new T [_capacity];
        for (int i = 0; i < oldObj.size(); ++i) {
            temp[i]= oldObj[i];
            _size++;
        }
        this->~vector();
        arr = temp;
    }
    return *this;
}

template<typename T>
void vector<T>::resize() {
    _capacity *= 2;
        T *temp = new T[_capacity*2];
        for(int i=0; i<_size;i++)
        {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
}

template<typename T>
void vector<T>::pop_back() {
    _size -= 1;
    T *temp = new T[_size-1];
    for(int i = 0; i<_size-1; i++)
    {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}


template<typename T>
int vector<T>::operator[](unsigned int index) const {
    return arr[index];
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const vector<T> &a) {
    for(int i=0; i<a._size; ++i) {
        std::cout << *(a.arr + i) << " ";
    }
    return out;
}


#endif