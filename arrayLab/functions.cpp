//
// Created by hoben on 1/24/2023.
//

#include "functions.h"

void print(int array[], int &size, int numUsed) {
    outOfBound(size, numUsed);
    for (int i = 0; i < numUsed; ++i) {
        std::cout<< array[i] << " ";
    }
    std::cout<<"\n";
}

void fill(int array[], int &size, int defaultValue) {
    //fills array with defaultValue
    for (int i = 0; i < size; ++i) {
        array[i] = defaultValue;
    }
}

void fill(int array[], int &size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;

    }
}

void shiftLeft(int array[], int &size, int &numUsed, int index) {
    //shifts all values to the left, starting at index
    outOfBound(size, numUsed);
    for (int i= index; i < numUsed; ++i) {
        array[i] = array[i+1];
        //numUsed--;
    }
}

void shiftRight(int array[], int &size, int &numUsed, int index) {
    //shifts all values to the right, starting at index
    outOfBound(size, numUsed);
    for (int i = numUsed; i >= index; --i) {
        array[i] = array[i-1];
        //numUsed++;
    }
}
void remove(int arr[], int &size, int &numUsed, int value) {
    outOfBound(size, numUsed);
    for (int i = 0; i < numUsed; ++i)
    {
        if (arr[i]==value)
        {
            shiftLeft(arr,size,numUsed,i);
            numUsed--;
        }
    }
}
void insert(int arr[], int &size, int &numUsed, int value, int index)
{
    outOfBound(size, numUsed);
    shiftRight(arr,size,numUsed,index);
    arr[index-1] = value;
}

void bubbleSort(int array[], int &size, int numUsed){
    outOfBound(size, numUsed);
    for (int i = 0; i < numUsed; ++i) {
        for(int j = 0; j<numUsed-1; ++j)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void outOfBound(int& size, int numUsed)
{
    if(size<numUsed)
    {
        size=numUsed;
        std::cout<<"resizing the array"<<std::endl;
    }
}


void run(){
    int size = 0;
    int array[100];
    int numUsed = 0, defaultValue = 0;
    int index = 2, value = 0;
    std::cout<<"Size of array?"<<std::endl;
    std::cin>>size;
    std::cout<<"How many array do you want?"<<std::endl;
    std::cin>>numUsed;
    fill(array,size,defaultValue);
    fill(array,size);
    std::cout<<"printing!"<<std::endl;
    print(array, size, numUsed);
    std::cout<<"Shifting Left!"<<std::endl;
    shiftLeft(array,size,numUsed,index);
    print(array, size, numUsed);
    std::cout<<"Shifting Right!"<<std::endl;
    shiftRight(array,size,numUsed,index);
    print(array, size, numUsed);
    std::cout<<"Insert value: "<<value<<" at index "<<index<< std::endl;
    insert(array,size,numUsed,value,index);
    print(array, size, numUsed);
    std::cout<<"removing value: "<<value<< std::endl;
    remove(array,size,numUsed,value);
    print(array,size,numUsed);
    std::cout<<"Sorting!"<<std::endl;
    bubbleSort(array,size,numUsed);
    print(array, size, numUsed);

}

