#include <iostream>
#include <cstdlib>
#include "postfixCalculator.h"
#include "stack.h"
using namespace std;
PostFixCalculator::PostFixCalculator()
{
	total = new Stack();
}
  void PostFixCalculator::add()
  {
    int top = total->top();
    total->pop();
    int bot = total->top();
    total->pop();
    total->push( top+bot);
  }
  void PostFixCalculator::sub()
  {
    int top = total->top();
    total->pop();
    int bot = total->top();
    total->pop();
    total->push(bot-top);
  }
  void PostFixCalculator::div()
  {
    int top = total->top();
    total->pop();
    int bot = total->top();
    total->pop();
    total->push(bot/top);
  }
  void PostFixCalculator::mult()
  {
    int top = total->top();
    total->pop();
    int bot = total->top();
    total->pop();
    total->push(top*bot);
  }
  void PostFixCalculator::neg()
  {
    int top = total->top();
    total->pop();
    total->push(top*-1);
  }
  void PostFixCalculator::pushNum(int num)
  {
    total->push(num);
  }
  int PostFixCalculator::getTopValue()
  {
    return total->top();
  }
