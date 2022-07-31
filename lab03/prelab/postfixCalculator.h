#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;
class PostFixCalculator{
 public:
  PostFixCalculator();
  stack<int> total;
  void add();
  void sub();
  void div();
  void mult();
  void neg();
  void pushNum(int num);
  int getTopValue();
};
#endif
