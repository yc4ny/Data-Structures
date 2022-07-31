#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include <iostream>
using namespace std;
//Default Constructor
List::List()
{
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;
}
//Destructor
List::~List()
{
  makeEmpty();
  delete head;
  delete tail;
  
}
List::List(const List& source) {      // Copy Constructor
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       // deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List& List::operator=(const List& source) { //Equals operator
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}
//returns true if the list is empty, else false
bool List::isEmpty() const
{
  if(count==0){return true;}
  return false;
}
//removes all nodes except the dummy nodes
void List::makeEmpty()
{
  ListItr position = first();
  ListNode *n = new ListNode();
 while(!position.isPastEnd())
    {
      // current = head->next;
      n = position.current;
      position.moveForward();
      delete n;      
    }
  count = 0;
  head->next = tail;
  tail->previous = head;
}
//Returns an iterator that points to the ListNode in the 
//first position
ListItr List::first()
{
  return ListItr(head->next);
}
//Returns an iterator that points to the ListNode in the last position
ListItr List::last()
{
  return ListItr(tail->previous);
}
//inserts x after current iterator position p
void List::insertAfter(int x, ListItr position)
{
  ListNode *n = new ListNode(x);
  position.current->next->previous = n;
  n->next = position.current->next;
  position.current->next = n;
  n->previous = position.current;
  count++;
}
//inserts x before current iterator position p                                          
void List::insertBefore(int x, ListItr position)
{
  ListNode *n = new ListNode(x);
  position.current->previous->next = n;
  n->previous = position.current->previous;
  position.current->previous = n;
  n->next = position.current;
  count++;
}
//insert x at tail of list
void List::insertAtTail(int x)
{
  ListNode *n = new ListNode(x);
  n->next = tail;
  n->previous = tail->previous;
  tail->previous->next = n;
  tail->previous = n;
  count++;
}
//removes first occurence of x
void List::remove(int x)
{
  ListItr iter = find(x);
  if(iter.current==tail)
    {
      cout << "Number is not in the list"<<endl;
      return;
    }
  iter.current->previous->next = iter.current->next;
  iter.current->next->previous = iter.current->previous;
  delete iter.current;
  count--;
}
//Returns an iterator that points to the first occurrence of x,
//else return a iterator to the dummy tail node
ListItr List::find(int x)
{
  ListItr iter(head->next);
  while(iter.isPastEnd()==false && iter.retrieve()!=x){
    iter.moveForward();
  }
  if(iter.current==NULL)
    iter.current = tail;
  return iter;
}
//returns numbers of elements in the list
int List::size() const
{
  return count;
}
//prints list forward when direction is true
//or backwards when direction is false
void printList(List& source, bool direction)
{
  if(direction){
    ListItr iter(source.getHead()->getNext());
    while(iter.retrieve())
    {
      cout << iter.retrieve() <<endl;
      iter.moveForward();
    }
  }
  else{
    ListItr iter(source.getTail()->getPrevious());
    while(iter.retrieve())
      {
	cout << iter.retrieve() << endl;
	iter.moveBackward();
      }
  }
}
ListNode* List::getHead()
{
  return head;
}
ListNode* List::getTail()
{
  return tail;
}
