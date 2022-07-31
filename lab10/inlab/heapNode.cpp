#include <iostream>
#include "heapNode.h"
#include <string>
using namespace std;
heapNode::heapNode()
{
  left = NULL;
  right = NULL;
  data = '\0';
  count = 1;
}
heapNode::heapNode(int f,char info)
{
  left =NULL;
  right =NULL;
  data = info;
  count = f;
}
void heapNode::inc()
{
  count++;
}
int heapNode::getCount() const
{
  return count;
}
char heapNode::getAlpha()
{
  return data;
}
bool heapNode::operator<(const heapNode& n) const{
  return(this->getCount()<n.getCount());
}
void heapNode::setCount(int s)
{
  count = s;
}
