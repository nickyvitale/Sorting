#include <iostream>
#include "utility.h"
#include "heap.h"
#include "sorting.h"

// Heap sort:
void heapSort(int *arr, int length){
    Heap myHeap(arr, length);

    for(int i = 0; i < length; i++){
        arr[i] = myHeap.extractMin();
    }
}

// Used by quick sort
// Just uses the first element as partition
// Return value: new index of pivot
int partition(int *arr, int left, int right){
    int pivot = left;

    int nextBigger = left+1;
    int nextSmaller = right;

    while (true){
        while (nextSmaller > left && arr[nextSmaller] > arr[pivot]){
            nextSmaller--;
        }
        while (nextBigger <= right && arr[nextBigger] <= arr[pivot]){
            nextBigger++;
        }

        if (nextBigger < nextSmaller){
            swap(arr[nextSmaller], arr[nextBigger]);   
        }
        else{
            break;
        }
    }
    swap(arr[nextSmaller], arr[pivot]);
    return nextSmaller;
}

// Quick sort:
// To call on whole arr: quickSort(arr, 0, length-1)
void quickSort(int *arr, int left, int right){
    if (left >= right){
        return;
    }

    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}

// Used by merge sort to merge sorted arrays into a
// single sorted array
void merge(int *arr, int left, int right){
    int middle = (left+right)/2;

    // Temp arrays
    int leftSize = middle-left+1;
    int rightSize = right-middle;
    int *leftArr = new int[leftSize];
    int *rightArr = new int[rightSize];

    // Populate temp arrays
    for (int i = 0; i < leftSize; i++){
        leftArr[i] = arr[left+i];
    }
    for(int i = 0; i < rightSize; i++){
        rightArr[i] = arr[middle+1+i];
    }

    // Perform merge
    int leftPointer = 0;
    int rightPointer = 0;
    int arrPointer = left;
    while(arrPointer <= right){
        if (leftPointer >= leftSize){
            arr[arrPointer] = rightArr[rightPointer];
            rightPointer++;
        }
        else if (rightPointer >= rightSize){
            arr[arrPointer] = leftArr[leftPointer];
            leftPointer++;
        }

        else if (leftArr[leftPointer] <= rightArr[rightPointer]){
            arr[arrPointer] = leftArr[leftPointer];
            leftPointer++;
        }
        else{
            arr[arrPointer] = rightArr[rightPointer];
            rightPointer++;
        }
        arrPointer++;
    }

    delete [] leftArr;
    delete [] rightArr;
}

// Merge sort:
// To call on whole array, use: mergeSort(arr, 0, length-1)
void mergeSort(int *arr, int left, int right){
    if (left >= right){ // if array is only a single element
        return;
    }

    int middle = (left+right)/2;
    mergeSort(arr, left, middle); // MergeSort the left
    mergeSort(arr, middle + 1, right); // MergeSort the right
    merge(arr, left, right); // Merge the two sorted halves
}

// Bubble sort:
// Best case runtime: O(n) (with optimization of "swapped" boolean)
void bubbleSort(int *arr, int length){
    bool swapped = false;

    for (int i = 0; i < length; i++){
        for(int j = 0; j < length-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped){
            return; // no swaps were made-> already in sorted order  
        }
        swapped = false;
    }
}

// Selection Sort:
// Fewer swaps than bubble sort, but best case runtime is O(n^2)
void selectionSort(int *arr, int length){
    for (int i = 0; i < length-1; i++){
        int min = i;
        for (int j = i + 1; j < length; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }

        if (min != i){ // only swap if necessary
            swap(arr[min], arr[i]);
        }
    }
}

// Insertion Sort:
void insertionSort(int *arr, int length){
    for (int i = 1; i < length; i++){
        int j = i;
        while (j > 0){
            if (arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
                j--;
            }
            else{
                break;
            }
        }
    }
}