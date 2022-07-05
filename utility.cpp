#include <iostream>
#include "utility.h"

// Swap function used by many of the sort algorithms
void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

// Used to print an array from first element to last
void printArray(int *arr, int length){
    for(int i = 0; i < length; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Traverses through array, checks if it is sorted
bool isSorted(int *arr, int length){
    if (length == 1){
        return true;
    }

    for (int i = 0; i < length-1; i++){
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}