//
// Created by Ben Ho on 2/19/2023.
//

#ifndef CHP11P1_VECTORDOUBLE_H
#define CHP11P1_VECTORDOUBLE_H

#include <iostream>
#include <vector>
class VectorDouble {
private:
    int max_count = 0;
    int count = 0;
    double * array;
public:
    VectorDouble();
    VectorDouble(int number);
    VectorDouble(VectorDouble &oldObj);
    ~VectorDouble();
    void operator =(VectorDouble &oldObj);
    bool friend operator ==(const VectorDouble &A1, const VectorDouble &A2);
    void push_back(int number);
    int size() const;
    int capacity() const;
    void reserve(int number);
    void resize( int number);
    double value_at(int index);
    void change_value_at (double number, int index);
    int getArray(double *array, int index);
};



#endif //CHP11P1_VECTORDOUBLE_H
