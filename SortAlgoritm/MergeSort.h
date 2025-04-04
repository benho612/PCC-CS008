//
// Created by hoben on 11/14/2023.
//

#ifndef SORTALGORITM_MERGESORT_H
#define SORTALGORITM_MERGESORT_H


class MergeSort {
public:
    void mergeSort(int array[], int const begin, int const end);
    void merge(int array[], int const left, int const mid, int const right);
};


#endif //SORTALGORITM_MERGESORT_H
