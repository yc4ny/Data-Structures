// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
#ifndef HEAP_NODE_H
#define HEAP_NODE_H

#include <vector>
using namespace std;

class heapNode {
public:
    heapNode();
    heapNode(int f,char info);
    int getCount() const;
    char  getAlpha();
     void setCount(int s);
   void inc();
   heapNode *left;
   heapNode *right;
   bool operator<(const heapNode& n) const;
private:
    char  data;
    int count;
    friend class heap;
};
#endif
