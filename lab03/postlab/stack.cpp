#include <iostream>
#include "stack.h"
#include <cstdlib>
#include "postfixCalculator.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include <string>
using namespace std;

Stack::Stack()
{
  stack = new List();
  count = 0;
}

Stack::~Stack()
{
  delete stack;
}

void Stack::push(int e)
{
  if(empty())
    itr = stack->first();
  stack->insertBefore(e,itr);
  count++;
}
int Stack::top()
{
  itr.moveBackward();
  int num = itr.retrieve();
  itr.moveForward();
  return num;
}

void Stack::pop()
{
  int num = top();
  stack->remove(num);
}

bool Stack::empty()
{
  if(count == 0)
    return true;
  return false;
}
