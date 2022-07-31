// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H
#include "heapNode.h"
#include <vector>
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<heapNode*> vec);
    ~binary_heap();

    void insert(heapNode* ptr);
    heapNode* findMin();
    void deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    vector<heapNode*> vec();
private:
    vector<heapNode*> heap;
    unsigned int heap_size;

    void percolateUp(headNode* hole1);
    void percolateDown(headNode* hole1);
};

#endif
