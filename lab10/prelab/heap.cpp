// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "heapNode.h"
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    heap.push_back(0);
}

// builds a heap from an unsorted vector
binary_heap::binary_heap(vector<heapNode*> vec) : heap_size(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    heap[0] = NULL;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
binary_heap::~binary_heap() {
}

void binary_heap::insert(heapNode * ptr) {
    // a vector push_back will resize as necessary
    heap.push_back(ptr);
    // move it up into the right position
    percolateUp(++heap_size);
}

void binary_heap::percolateUp(int  hole) {
    // get the value just inserted
    int x = heap[hole]->count;
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < heap[hole/2]->count); hole /= 2 )
        heap[hole] = heap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
     
    heap[hole] = &f;
}

int binary_heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    int ret = heap[1]->count;
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void binary_heap::percolateDown(heapNode* hole1) {
    // get the value to percolate down
  int hole = hole1->count;
    int x = heap[hole]->count;
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (heap[child+1]->count < heap[child]->count) )
            child++;
        // if the child is greater than the node...
        if ( x > heap[child]->count ) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heapNode q = hole1;
    hole1->count =x;
    heap[hole] = &hole1;
}

int binary_heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heap[1]->count;
}

unsigned int binary_heap::size() {
    return heap_size;
}

void binary_heap::makeEmpty() {
    heap_size = 0;
}

bool binary_heap::isEmpty() {
    return heap_size == 0;
}

void binary_heap::print() {
    cout << "(" << heap[0]->data << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << heap[i]->data << " ";
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}
