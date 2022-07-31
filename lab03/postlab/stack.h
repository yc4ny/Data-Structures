#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include "postfixCalculator.h"
using namespace std;

class Stack {
 public:
  Stack(); //Constructor
  ~Stack(); //Destructor
  void push(int e); //adds passed element to the stack
  int top(); //returns element on the top of the stack
             //if stack is empty then exit program
  void pop(); //removes element on the top of the stack, but doesn't return it
              //if stack is empty then exit program
  bool empty(); //says whether stack is empty or not
 private:
  int count;
  List *stack;
  ListItr itr;
};
#endif
