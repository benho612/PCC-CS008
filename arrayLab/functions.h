//
// Created by hoben on 1/24/2023.
//

#ifndef ARRAYLAB_FUNCTIONS_H
#define ARRAYLAB_FUNCTIONS_H
#include<iostream>
#include <array>
#include <ctime>
#include <cstdlib>
//prints all used variable in array
void print(int array[], int &size, int numUsed);

//fills array with defaultValue
void fill(int array[], int &size, int defaultValue);

//fills array with random values
void fill(int array[], int &size);

//shifts all values to the left, starting at index
void shiftLeft(int array[], int &size, int& numUsed, int index);

//shifts all values to the right, starting at index
void shiftRight(int array[], int &size, int& numUsed, int index);

//remove first instance of value from the array
void remove(int arr[], int &size, int& numUsed, int value);

//insert value at given index
void insert(int arr[], int &size, int &numUsed, int value, int index);

//sorts array in ascending order using the bubble sort algorithm
void bubbleSort(int array[], int &size, int numUsed);

void outOfBound(int& size, int numUsed);

void run();
#endif //ARRAYLAB_FUNCTIONS_H
