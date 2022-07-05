#ifndef HEAP_H
#define HEAP_H

class Heap{
    private:
        int length;
        int *arr;
        void heapify(int i);
        void buildHeap();
    public:
        Heap(int *array, int len);
        ~ Heap();
        int extractMin();
};

#endif