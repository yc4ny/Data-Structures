#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
#include <cstdlib>
using namespace std;
class Stack; 
class PostFixCalculator{
 public:
  PostFixCalculator();
  Stack *total;
  void add();
  void sub();
  void div();
  void mult();
  void neg();
  void pushNum(int num);
  int getTopValue();
};
#endif
