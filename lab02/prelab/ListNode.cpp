#include "ListNode.h"
#include <iostream>
using namespace std;

ListNode::ListNode()
{
  value = 0;
  next = NULL;
  previous = NULL;
}

ListNode::ListNode(int val)
{
  value = val;
  next = NULL;
  previous = NULL;
}

ListNode::ListNode(int val, ListNode *n, ListNode *p)
{
  value = val;
  next = n;
  previous = p;
}
ListNode* ListNode::getNext()
{
	return next;
}
ListNode* ListNode::getPrevious()
{
	return previous;
}
