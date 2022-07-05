#include <iostream>
#include "utility.h"
#include "sorting.h"
#include <string>
#include <cstdlib>
#include <time.h>

enum algorithm {heapSrt, mergeSrt, quickSrt, bubbleSrt, insertionSrt, selectionSrt};

int testRandomArray(algorithm alg){
    srand(time(0)); // seeds random generator using current time
    int length = rand();
    int *arr = new int[length];
    for(int i = 0; i < length; i++){
        arr[i] = rand();
    }

    int toReturn = 0;
    switch(alg){
        case heapSrt:
            heapSort(arr, length);
            if (!isSorted(arr, length)){
                std::cout << "Heapsort failed\n";
                toReturn = -1;
            }
            break;
        
        case mergeSrt:
            mergeSort(arr, 0, length-1);
            if (!isSorted(arr, length)){
                std::cout << "Mergesort failed\n";
                toReturn = -1;
            }
            break;
        
        case quickSrt:
            quickSort(arr, 0, length-1);
            if (!isSorted(arr, length)){
                std::cout << "Quicksort failed\n";
                toReturn = -1;
            }
            break;
        
        case bubbleSrt:
            bubbleSort(arr, length);
            if (!isSorted(arr, length)){
                std::cout << "Bubblesort failed\n";
                toReturn = -1;
            }
            break;
        
        case insertionSrt:
            insertionSort(arr, length);
            if (!isSorted(arr, length)){
                std::cout << "Insertionsort failed\n";
                toReturn = -1;
            }
            break;

        case selectionSrt:
            selectionSort(arr, length);
            if (!isSorted(arr, length)){
                std::cout << "Selectionsort failed\n";
                toReturn = -1;
            }  
            break;

        default:
            std::cout << "Couldn't run testEmptyArr: invalid algorithm\n";
            toReturn = -1;
            break;
    }
    
    delete [] arr;
    return toReturn;
}

int runAllTests(){
    int toReturn = 0;
    for(int i = 0; i < 1; i++){ // do 100 times
        if(testRandomArray(heapSrt) == -1 ||
        testRandomArray(mergeSrt) == -1 ||
        testRandomArray(quickSrt) == -1 ||
        testRandomArray(bubbleSrt) == -1 ||
        testRandomArray(insertionSrt) == -1 ||
        testRandomArray(selectionSrt) == -1){
            toReturn = -1;
        }
    }
    return toReturn;
}

// Main is driver function to call tests
int main(){
    if (runAllTests() != -1){
        std::cout << "All test cases passed\n";
    }

    return 0;
}