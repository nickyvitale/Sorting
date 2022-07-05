#include <iostream>
#include "heap.h"
#include "utility.h"

Heap::Heap(int *array, int len){
    arr = new int[len+1];
    length = len;

    // Copy over array, shifted over one
    arr[0] = -1; // Will be ignored
    for(int i = 0; i < len; i++){
        arr[i+1] = array[i];
    }

    buildHeap();
}

Heap::~Heap(){
    delete [] arr;   
}

void Heap:: heapify(int i){
    int min;

    if (2*i > length){
        return; // is leaf
    }
    else if (2*i + 1 > length){
        min = 2*i;
    }
    else if (arr[2*i] <= arr[2*i+1]){
        min = 2*i;
    }
    else{
        min = 2*i+1;
    }

    if (arr[i] > arr[min]){
        swap(arr[i], arr[min]);
        heapify(min);
    }
}

int Heap::extractMin(){
    swap(arr[1], arr[length]);
    int toReturn = arr[length];
    length--;

    heapify(1);
    return toReturn;
}

void Heap::buildHeap(){
    for (int i = length; i > 0; i--){
        heapify(i);
    }
}