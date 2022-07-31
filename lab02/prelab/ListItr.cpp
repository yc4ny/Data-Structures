#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include <iostream>
using namespace std;
//Default Constructor
ListItr::ListItr()
{
  current = NULL;
}
//one parameter constructor
ListItr::ListItr(ListNode *theNode)
{
  current = theNode;
}
/*Returns true if the iterator is currently pointing past the end position in
 the list (i.e., it's pointing to the dummy tail)*/
bool ListItr::isPastEnd() const
{
  if(current->next==NULL){return true;}
  return false;
}
/*Returns true if the iterator is currently pointing past(before) the first
 position in list (i.e., it's pointing to the dummy head)*/
bool ListItr::isPastBeginning() const
{
  if(current->previous==NULL){ return true;}
  return false;
}
/*Advances the current pointer to the next position in the list
  (unless already past the end of the list)*/
void ListItr::moveForward()
{
  if(isPastEnd()){return;}
  current = current->next;
}
/*Move current back to the previous position in the list
 (unless already past the beginning of the list)*/
void ListItr::moveBackward()
{
  if(isPastBeginning()){return;}
  current = current->previous;
}
/*Returns the value of the item in the current position of the list*/
int ListItr::retrieve() const
{
  return current->value;
}
